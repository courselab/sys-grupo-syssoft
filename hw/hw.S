	## Boot, say hello, and halt
	## AT&T assembly, translated from NASM

    .code16                # Set 16-bit code

    .global begin	       # So the linker can find it.

begin:		               # Program beginning (no equivalent to NASM $$)
	
    mov   $0xe, %ah	       # BIOS tty mode
	
    mov   $0x48, %al       # Load 'H'
    int   $0x10	           # Call bios
	
    mov   $0x65, %al       # Load 'e'
    int   $0x10	           # Call bios
	
    mov   $0x6C, %al       # Load 'l'
    int   $0x10	           # Call bios
	
    mov   $0x6C, %al       # Load 'l'
    int   $0x10	           # Call bios
	
    mov   $0x6F, %al       # Load 'o'
    int   $0x10	           # Call bios
	
    mov   $0x20, %al       # Load ' '
    int   $0x10	           # Call bios
	
    mov   $0x57, %al       # Load 'W'
    int   $0x10	           # Call bios
	
    mov   $0x6F, %al       # Load 'o'
    int   $0x10	           # Call bios
	
    mov   $0x72, %al       # Load 'r'
    int   $0x10	           # Call bios
	
    mov   $0x6C, %al       # Load 'l'
    int   $0x10	           # Call bios
	
    mov   $0x64, %al       # Load 'd'
    int   $0x10	           # Call bios

halt:
	hlt		       # Halt
	jmp   halt	       # Safeguard

	.fill 510 - (. - begin), 1, 0       # Pad with zeros
	.word 0xaa55			    # Boot signature
