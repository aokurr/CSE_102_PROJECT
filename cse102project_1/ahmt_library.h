#ifndef ahmt_library
#define ahmt_library
typedef struct p{
	double x,y;
	struct p *next;

}Point2D;

typedef struct c{
	double red,green,blue;

}Color;

typedef struct f{
	double llx,lly;
	double width,height;
	double thickness,resolution;
	Point2D *point;
	Color c;
	int closepath;
	int break_;
	int eof;


}Figure;


typedef struct n{
	int data;
	struct n *left;
	struct n *right;

}Tree;
Figure * start_figure(double width, double height);
void set_thickness_resolution(Figure * fig, double thickness, double resolution);

void set_color(Figure * fig, Color c);

void draw_fx(Figure * fig, double f(double x), double start_x, double end_x,double step_size);

double sinx(double x);

void export_eps(Figure * fig, char * file_name);

void draw_polyline(Figure * fig,Point2D * poly_line, int n);

void draw_polygon(Figure *fig,Point2D * poly_line);

void draw_ellipse(Figure *fig,Point2D * centre, Point2D * width_height);
/*for draw tree*/
void draw_binary_tree(Figure *fig,Tree * root);
/*for draw tree*/
void circle_binary_tree(Figure *fig,double x,double y,double size);
/*for draw tree*/
void dolas_prefix(Figure *fig,Tree *root,double x,double y,int *count,double size,char *file_name);

void scale_figure(Figure *fig,double scale_x, double scale_y);

void resize_figure(Figure *fig,Point2D *start_roi, Point2D *end_roi);
void append_figures(Figure * fig1, Figure * fig2);
#endif