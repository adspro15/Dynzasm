#include "disas.h"

int main()
{

  struct disassembler *ds = ds_init(X86_ARCH, MODE_64B);
  unsigned char bytes[] =  "\x55\x48\x89\xe5\xb8\x00\x00\x00\x00\xc3";

  ds_decode(ds, bytes, sizeof(bytes)-1, 0x0);
  struct dis *dis = NULL;

  DS_FOREACH(ds, dis) {
    printf("%#08lx:\t%s\t%s\n", dis->address, dis->mnemonic, dis->op_squash);
  }

  ds_destroy(ds);
  struct disassembler *ds = ds_init(MIPS_ARCH, MODE_64B);
  unsigned char bytes[] =  "\x55\x48\x89\xe5\xb8\x00\x00\x00\x00\xc3";

  ds_decode(ds, bytes, sizeof(bytes)-1, 0x0);
  struct dis *dis = NULL;

  DS_FOREACH(ds, dis) {
    printf("%#08lx:\t%s\t%s\n", dis->address, dis->mnemonic, dis->op_squash);
  }

  ds_destroy(ds);
  ds_destroy(ds);
  return 0;
}
