#include <stdio.h>
#include <string.h>
struct op {
 char l;
 char r[50]; // Increased buffer size for more complex expressions
} op[10], pr[10];
void main() {
 int i, j, k, n, z = 0, m, q;
 char *p, *l;
 char temp, t;
 char *tem;
 printf("Enter the Number of Values: ");
 scanf("%d", &n);
 getchar(); // To consume the newline character left by scanf()
 // Input equations
 for (i = 0; i < n; i++) {
 printf("left: ");
 op[i].l = getchar(); // Read a single character for left-hand side
 getchar(); // Consume the newline character
 printf("\tright: ");
 scanf("%s", op[i].r); // Read the expression for the right-hand side
 getchar(); // Consume the newline character left by scanf()
 }
 // Step 1: Print Intermediate Code
 printf("Intermediate Code\n");
 for (i = 0; i < n; i++) {
 printf("%c=%s\n", op[i].l, op[i].r);
 }
 // Step 2: Dead Code Elimination
 for (i = 0; i < n - 1; i++) {
 temp = op[i].l;
 int is_used = 0;
 for (j = 0; j < n; j++) {
 p = strchr(op[j].r, temp);
 if (p) { // If the variable is used later
 is_used = 1;
 break;
 }
 }
 if (is_used) {
 pr[z].l = op[i].l;
 strcpy(pr[z].r, op[i].r);
 z++;
 }
 }
 // Copy the last expression (it’s always needed)
 pr[z].l = op[n - 1].l;
 strcpy(pr[z].r, op[n - 1].r);
 z++;
 // After Dead Code Elimination
 printf("After Dead Code Elimination\n");
 for (k = 0; k < z; k++) {
 printf("%c=%s\n", pr[k].l, pr[k].r);
 }
 // Step 3: Eliminate Common Expressions
 // Check for common expressions and eliminate them
 for (m = 0; m < z; m++) {
 tem = pr[m].r;
 for (j = m + 1; j < z; j++) {
 if (strcmp(pr[m].r, pr[j].r) == 0) { // If two expressions are the same
 t = pr[j].l;
 pr[j].l = pr[m].l; // Reuse the expression
 for (i = 0; i < z; i++) {
 l = strchr(pr[i].r, t);
 if (l) {
 int a = l - pr[i].r;
 pr[i].r[a] = pr[m].l; // Replace with the optimized variable
 }
 }
 }
 }
 }
 // After Common Expression Elimination
 printf("Eliminate Common Expression\n");
 for (i = 0; i < z; i++) {
 printf("\t%c=%s\n", pr[i].l, pr[i].r);
 }
 // Step 4: Optimized Code
 // Finally, print the optimized code
 printf("Optimized Code\n");
 for (i = 0; i < z; i++) {
 if (pr[i].l != '\0') { // Skip the eliminated expressions
 printf("%c=%s\n", pr[i].l, pr[i].r);
 }
 }
}
