#ifndef lib
#define lib
typedef struct n{
	double background_color[3];
	double foreground_color[3];
	double tile_size;
	double angle_offset[2];
	double canvas_size[2];
	int show_grid;
	int archetype;
	double pattern_thickness;
	double grid_color[3];
	double grid_thickness;
	char name[50];


}node;
char **read_commands(char **informations);
char **read_defaults(char **informations_defaults);

int control_error(char *informations);

void store_struct(node *root,char *informations,char **informations_defaults,int count);
void store_struct_defaults(node *root,char **informations_defaults,int array[10],int count);

void print_square(node *root,int count);
void print_hexagon(node *root,int count);
#endif
