program RS485_Master_Example

dim dat as byte[10]                                   ' buffer for receving/sending messages
    i, j as byte
    cnt as longint

dim rs485_rxtx_pin  as sbit at RC2_bit                ' set transcieve pin
    rs485_rxtx_pin_direction as sbit at TRISC2_bit    ' set transcieve pin direction

' Interrupt routine
sub procedure interrupt()
  RS485Master_Receive(dat)
end sub

main:
  cnt = 0
  ANSEL  = 0                        ' Configure AN pins as digital I/O
  ANSELH = 0

  C1ON_bit = 0                      ' Disable comparators
  C2ON_bit = 0

  PORTB  = 0
  PORTC  = 0
  TRISB  = 0
  TRISD  = 0

  UART1_Init(9600)                  ' initialize UART1 module
  Delay_ms(100)

  RS485Master_Init()                ' initialize MCU as Master
  dat[0] = 0xAA
  dat[1] = 0xF0
  dat[2] = 0x0F
  dat[4] = 0                        ' ensure that message received flag is 0
  dat[5] = 0                        ' ensure that error flag is 0
  dat[6] = 0

  RS485Master_Send(dat,1,160)

  RCIE_bit = 1                      ' enable interrupt on UART1 receive
  TXIE_bit = 0                      ' disable interrupt on UART1 transmit
  PEIE_bit = 1                      ' enable peripheral interrupts
  GIE_bit = 1                       ' enable all interrupts

  while TRUE                        ' upon completed valid message receiving
                                    '   data[4] is set to 255
    Inc(cnt)
    if (dat[5] <> 0) then           ' if an error detected, signal it
      PORTC = 0xAA                  '   by setting portC to 0xAA
    end if

    if (dat[4] <> 0) then           ' if message received successfully
      cnt = 0
      dat[4] = 0                    ' clear message received flag
      j = dat[3]
      for i = 1 to dat[3]           ' show data on PORTB
        PORTB = dat[i-1]
      next i
      dat[0] = dat[0]+1             ' increment received dat[0]
      Delay_ms(1)                   ' send back to slave
      RS485Master_Send(dat,1,160)
    end if

    if (cnt > 100000) then          ' if in 100000 poll-cycles the answer
      Inc(PORTC)                    '   was not detected, signal
      cnt = 0                       '   failure of send-message
      RS485Master_Send(dat,1,160)
      if (PORTC > 10) then          ' if sending failed 10 times
        RS485Master_Send(dat,1,50)  '   send message on broadcast address
      end if
    end if
  wend
end.