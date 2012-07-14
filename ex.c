/*
A Union is like a structure, except that each
element shares the same memory. Thus in this
example, the coords and about members overlap.

Note that the setting of about[2] to 'X' CORRUPTS
the float in this demonstration.

In a practical use, a variable such as un_type
(provided but not used in this example) would be
set up to indicate which particular use is being
made of the union

*/
typedef union {
        float coords[3];
        char about[20];
        } assocdata;

typedef struct {
        char *descript;
        int un_type;
        assocdata alsostuff;
        } leaf;

int main() {
        leaf oak[3];
        int i;

        printf ("Hello World\n");

        for (i=0; i<3; i++) {
                oak[i].descript = "A Greeting";
                oak[i].un_type = 1;
                oak[i].alsostuff.coords[0] = 3.14;
                }
        oak[2].alsostuff.about[2] = 'X';

        for (i=0; i<3; i++) {
                printf("%s\n",oak[i].descript);
                printf("%5.2f\n",oak[i].alsostuff.coords[0]);
                }

        }
