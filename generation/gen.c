#include<stdio.h>
#include<string.h>
char op[2], arg1[5], arg2[5], result[5];
void main()
{
 FILE *fp1, *fp2;
 fp1 = fopen("ip.txt", "r");
 fp2 = fopen("op.txt", "w");
 if (fp1 == NULL || fp2 == NULL) {
 printf("Error opening file(s)\n");
 return;
 }
 while (fscanf(fp1, "%s %s %s %s", op, arg1, arg2, result) != EOF) {
 if (strcmp(op, "+") == 0) {
 fprintf(fp2, "\nMOV R0,%s", arg1);
 fprintf(fp2, "\nADD R0,%s", arg2);
 fprintf(fp2, "\nMOV %s,R0", result);
 }
 else if (strcmp(op, "*") == 0) {
 fprintf(fp2, "\nMOV R0,%s", arg1);
 fprintf(fp2, "\nMUL R0,%s", arg2);
 fprintf(fp2, "\nMOV %s,R0", result);
 }
 else if (strcmp(op, "-") == 0) {
 fprintf(fp2, "\nMOV R0,%s", arg1);
 fprintf(fp2, "\nSUB R0,%s", arg2);
 fprintf(fp2, "\nMOV %s,R0", result);
 }
 else if (strcmp(op, "/") == 0) {
 fprintf(fp2, "\nMOV R0,%s", arg1);
 fprintf(fp2, "\nDIV R0,%s", arg2);
 fprintf(fp2, "\nMOV %s,R0", result);
 }
 else if (strcmp(op, "=") == 0) {
 fprintf(fp2, "\nMOV R0,%s", arg1);
 fprintf(fp2, "\nMOV %s,R0", result);
 }
 }
 fclose(fp1);
 fclose(fp2);
}
