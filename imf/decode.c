
undefined4 main(int param_1, char **param_2)

{
  char **ppcVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  FILE *__stream;
  int *piVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  int local_220;
  char local_214[256];
  char local_114[256];
  int local_14;
  undefined4 *local_10;

  ppcVar1 = param_2;
  local_10 = &param_1;
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  hashcheck();
  if (param_1 < 2)
  {
    pcVar2 = __xpg_basename(*ppcVar1);
    printf("Usage: %s <file-name>\n", pcVar2);
    /* WARNING: Subroutine does not return */
    exit(1);
  }
  pcVar2 = ppcVar1[1];
  printf("Access token: ");
  __isoc99_scanf(&DAT_0804a02e, local_214);
  obf(local_214, _key, 1);
  local_220 = 0;
  while ((*(int *)(token + local_220 * 4) != 0 &&
          (iVar3 = strcmp(*(char **)(token + local_220 * 4), local_214), iVar3 != 0)))
  {
    local_220 = local_220 + 1;
  }
  // This is the part of the code whe want to change the register value let's look at it in the asm
  if (*(int *)(token + local_220 * 4) == 0)
  {
    puts("Denied.");
    uVar4 = 1;
  }
  else
  {
    __stream = fopen(pcVar2, "r");
    if (__stream == (FILE *)0x0)
    {
      if (pcVar2 == (char *)0x0)
      {
        pcVar2 = "";
      }
      piVar5 = __errno_location();
      pcVar6 = strerror(*piVar5);
      fprintf(stderr, "%s (%s)\n", pcVar6, pcVar2);
      /* WARNING: Subroutine does not return */
      exit(1);
    }
    while (pcVar2 = fgets(local_114, 0x100, __stream), pcVar2 != (char *)0x0)
    {
      obf(local_114, _key, 0xffffffff);
      printf("%s", local_114);
    }
    putchar(10);
    uVar4 = 0;
  }
  if (local_14 == *(int *)(in_GS_OFFSET + 0x14))
  {
    return uVar4;
  }
  /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}