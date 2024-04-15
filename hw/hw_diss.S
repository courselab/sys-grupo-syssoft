make --quiet hw.bin/diss att 16  

hw.bin:     file format binary


Disassembly of section .data:

00000000 <.data>:
	...
  10:	00 00                	add    %al,(%bx,%si)
  12:	00 0e 00 0e          	add    %cl,0xe00
  16:	b0 48                	mov    $0x48,%al
  18:	cd 10                	int    $0x10
  1a:	cd 10                	int    $0x10
  1c:	b0 65                	mov    $0x65,%al
  1e:	cd 10                	int    $0x10
  20:	cd 10                	int    $0x10
  22:	b0 6c                	mov    $0x6c,%al
  24:	cd 10                	int    $0x10
  26:	cd 10                	int    $0x10
  28:	b0 6c                	mov    $0x6c,%al
  2a:	cd 10                	int    $0x10
  2c:	cd 10                	int    $0x10
  2e:	b0 6f                	mov    $0x6f,%al
  30:	cd 10                	int    $0x10
  32:	cd 10                	int    $0x10
  34:	b0 20                	mov    $0x20,%al
  36:	cd 10                	int    $0x10
  38:	cd 10                	int    $0x10
  3a:	b0 57                	mov    $0x57,%al
  3c:	cd 10                	int    $0x10
  3e:	cd 10                	int    $0x10
  40:	b0 6f                	mov    $0x6f,%al
  42:	cd 10                	int    $0x10
  44:	cd 10                	int    $0x10
  46:	b0 72                	mov    $0x72,%al
  48:	cd 10                	int    $0x10
  4a:	cd 10                	int    $0x10
  4c:	b0 6c                	mov    $0x6c,%al
  4e:	cd 10                	int    $0x10
  50:	cd 10                	int    $0x10
  52:	b0 64                	mov    $0x64,%al
  54:	cd 10                	int    $0x10
  56:	cd 10                	int    $0x10
	...
