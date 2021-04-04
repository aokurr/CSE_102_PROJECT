#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ahmt_library.h"
double sinx_(double x);
Tree *ekle(Tree *agac,int x);
int main(){
	Figure *fig1,*fig2,*fig,*fig3;
	Point2D *poly_line;
	Point2D *centre,*width_height;
	Color c;
	c.red=100;
	c.blue=300;
	c.green=0;
	
	fig3=start_figure(900,800);
	set_thickness_resolution(fig3,0.1,0.5);	
	set_color(fig3,c);
	draw_fx(fig3,sinx_,0,360,5);
	export_eps(fig3,"sinx.eps");

	fig1=start_figure(500,400);
	set_thickness_resolution(fig1,0.1,0.5);	
	set_color(fig1,c);
	
	poly_line=malloc(sizeof(Point2D));	
	draw_polyline(fig1,poly_line,3);	
	export_eps(fig1,"polyline.eps");
	
	draw_polygon(fig1,poly_line);
	export_eps(fig1,"polygon.eps");

	fig2=start_figure(500,400);
	set_thickness_resolution(fig2,0.1,0.5);	
	c.red=0;
	c.blue=300;
	c.green=0;
	set_color(fig2,c);
	
	
	centre=malloc(sizeof(Point2D));
	width_height=malloc(sizeof(Point2D));
	centre->x=20;
	centre->y=20;

	width_height->x=10;
	width_height->y=14;

	draw_ellipse(fig2,centre,width_height);
	export_eps(fig2,"elips.eps");

	append_figures(fig1,fig2);
	export_eps(fig1,"append.eps");
		
	scale_figure(fig2,4,4);
	export_eps(fig2,"elips_scale.eps");

	Point2D *start_roi,*end_roi;
	start_roi=malloc(sizeof(Point2D));
	start_roi->x=25;
	start_roi->y=25;

	end_roi=malloc(sizeof(Point2D));
	end_roi->x=25;
	end_roi->y=25;


	resize_figure(fig2,start_roi,end_roi);
	export_eps(fig2,"resize_elips.eps");


	fig=start_figure(500,400);
	set_thickness_resolution(fig,0.1,0.5);	
	c.red=0;
	c.blue=000;
	c.green=110;
	set_color(fig,c);



	Tree *agac=NULL;
	agac=ekle(agac,56);
	agac=ekle(agac,200);
	agac=ekle(agac,26);
	agac=ekle(agac,190);
	agac=ekle(agac,213);
	agac=ekle(agac,18);
	agac=ekle(agac,28);
	agac=ekle(agac,12);
	agac=ekle(agac,24);

	draw_binary_tree(fig,agac);	
	return 0;

}
Tree *ekle(Tree *agac,int x){
	if(agac==NULL){
		Tree *root= malloc(sizeof(Tree));
		root->left=NULL;
		root->right=NULL;
		root->data=x;
		return root;
	}

	if(agac->data < x){
		agac->right=ekle(agac->right,x);
		return agac;
	}
	
	agac->left=ekle(agac->left,x);
	
	return agac;
}
double sinx_(double x){
	double y;
	y=x*(3.14/180);
	y=sin(y);
	y=y*10;
	
	return y;
}