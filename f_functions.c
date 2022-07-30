#include <stdio.h>
#include <string.h>

int main () {
   FILE *fp;
   char c[] = "Mrigendra Chaubey";
   char buffer[100];

   /* Open file for both reading and writing */
   fp = fopen("file.txt", "w+");

   /* Write data to the file */
   fwrite(c, strlen(c) + 1, 1, fp);

   /* Seek to the beginning of the file */
   fseek(fp, 0, SEEK_SET);

   /* Read and display data */
   fread(buffer, strlen(c)+1, 1, fp);
   printf("%s\n", buffer);
   fclose(fp);

   char str1[10], str2[10], str3[10];
   int year;


   fp = fopen ("file.txt", "w+");
   fputs("white spaces are 2022", fp);
   
//   rewind(fp);//moves the file pointer at beginning of the file
   fseek(fp, 0, SEEK_SET);//moves the file pointer at beginning of the file
   fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);
   
   printf("Read String1 |%s|\n", str1 );
   printf("Read String2 |%s|\n", str2 );
   printf("Read String3 |%s|\n", str3 );
   printf("Read Integer |%d|\n", year );

   fclose(fp);

   return(0);
}
