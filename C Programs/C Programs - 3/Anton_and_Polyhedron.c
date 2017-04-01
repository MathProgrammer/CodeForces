#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_faces_of_polyhedara(short *, unsigned int);
unsigned int get_total_number_of_faces(short *, unsigned int);
int main()
{
    unsigned int no_of_polyhedra, no_of_faces;
    scanf("%u",&no_of_polyhedra);

    short *polyhedra_face = malloc(no_of_polyhedra*sizeof(short));
    read_faces_of_polyhedara(polyhedra_face, no_of_polyhedra);
    no_of_faces = get_total_number_of_faces(polyhedra_face, no_of_polyhedra);

    printf("%u\n",no_of_faces);
    free(polyhedra_face);
    return 0;
}

void read_faces_of_polyhedara(short *polyhedra_face, unsigned int no_of_polyhedra)
{
    char current_polyhedra[15];
    unsigned int i;

    for(i = 0; i < no_of_polyhedra; i++)
    {
        scanf("%s",current_polyhedra);

        if(strcmp(current_polyhedra, "Tetrahedron") == 0)
        {
            *(polyhedra_face + i) = 4;
        }
        else if(strcmp(current_polyhedra, "Cube") == 0)
        {
            *(polyhedra_face + i) = 6;
        }
        else if(strcmp(current_polyhedra, "Octahedron") == 0)
        {
            *(polyhedra_face + i) = 8;
        }
        else if(strcmp(current_polyhedra, "Dodecahedron") == 0)
        {
            *(polyhedra_face + i) = 12;
        }
        else if(strcmp(current_polyhedra, "Icosahedron") == 0)
        {
            *(polyhedra_face + i) = 20;
        }
    }
}

unsigned int get_total_number_of_faces(short *polyhedra_face, unsigned int no_of_polyhedra)
{
    unsigned int i, total_faces = 0;

    for(i = 0; i < no_of_polyhedra; i++)
    {
        total_faces = total_faces + *(polyhedra_face + i);
    }
    return total_faces;
}
