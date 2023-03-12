#include <mySimpleComputer.h>

int
main ()
{
  int value = 0;
  sc_memoryInit ();
  printf ("\nинициализирована память\n");
  for (int i = 0; i < RAM_SIZE / 10; i++)
    sc_memorySet (i, i + 1);
  for (int i = 0; i < RAM_SIZE / 10; i++)
    {
      sc_memoryGet (i, &value);
      printf ("RAM[%d] = %d\n", i, value);
    }

  sc_memorySave ("test.bin");
  printf ("\nсохранение файла\n");
  sc_memorySet (0, 99);
  sc_memoryGet (0, &value);
  printf ("RAM[0] = %d\n", value);
  sc_memoryLoad ("test.bin");
  printf ("\nчтение файла\n");
  for (int i = 0; i < RAM_SIZE / 10; i++)
    {
      sc_memoryGet (i, &value);
      printf ("RAM[%d] = %d\n", i, value);
    }

  sc_regInit ();
  sc_regSet (FLAG_T, 1);
  printf ("\nподнят флаг для игнорирования тактовых импульсов\n");
  sc_regGet (FLAG_P, &value);
  printf ("flag P = %d\n", value);
  sc_regGet (FLAG_0, &value);
  printf ("flag 0 = %d\n", value);
  sc_regGet (FLAG_M, &value);
  printf ("flag M = %d\n", value);
  sc_regGet (FLAG_T, &value);
  printf ("flag T = %d\n", value);
  sc_regGet (FLAG_E, &value);
  printf ("flag E = %d\n", value);

  int encode, oper, com;
  sc_commandEncode (0x33, 0x59, &encode);
  printf ("encode = %x\n", encode);
  sc_commandDecode (encode, &com, &oper);
  printf ("command = %x\noperand = %x\n", com, oper);
  return 0;
}
