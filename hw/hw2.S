	## Boot, say hello, and halt
	## AT&T assembly, translated from NASM

    .code16                # Set 16-bit code

    .global begin	       # So the linker can find it.

begin:		               # Program beginning (no equivalent to NASM $$)
	
    mov   $0xe, %ah	       # BIOS tty mode
	
    mov   $'H', %al       # Load 'H'
    int   $0x10	           # Call bios
	
    mov   $'e', %al       # Load 'e'
    int   $0x10	           # Call bios
	
    mov   $'l', %al       # Load 'l'
    int   $0x10	           # Call bios
	
    mov   $'l', %al       # Load 'l'
    int   $0x10	           # Call bios
	
    mov   $'o', %al       # Load 'o'
    int   $0x10	           # Call bios
	
    mov   $' ', %al       # Load ' '
    int   $0x10	           # Call bios
	
    mov   $'W', %al       # Load 'W'
    int   $0x10	           # Call bios
	
    mov   $'o', %al       # Load 'o'
    int   $0x10	           # Call bios
	
    mov   $'r', %al       # Load 'r'
    int   $0x10	           # Call bios
	
    mov   $'l', %al       # Load 'l'
    int   $0x10	           # Call bios
	
    mov   $'d', %al       # Load 'd'
    int   $0x10	           # Call bios

halt:
	hlt		       # Halt
	jmp   halt	       # Safeguard

	.fill 510 - (. - begin), 1, 0       # Pad with zeros
	.word 0xaa55			    # Boot signature
