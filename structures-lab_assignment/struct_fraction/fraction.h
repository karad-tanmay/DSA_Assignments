typedef struct fraction{
    int nume;
    int denom;
}fraction;

void init(fraction *a, int nume, int denom);
void display(fraction a);
int cmp_fraction(fraction a, fraction b);