@make the reset visible from other files
.global reset
reset:
		ldr sp, =stack_top
		bl main	
stop: b stop
