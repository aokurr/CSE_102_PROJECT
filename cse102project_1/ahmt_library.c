#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ahmt_library.h"
Figure * start_figure(double width, double height){
	Figure *x;
	x=malloc(sizeof(Figure));
	x->width=width;
	x->height=height;
	x->llx=0;
	x->lly=0;
	x->break_=0;
	x->closepath=0;
	x->eof=0;
	
	return x;	
}
void set_thickness_resolution(Figure * fig, double thickness, double resolution){
	fig->resolution=resolution;
	fig->thickness=thickness;

}
void set_color(Figure * fig, Color c){
	fig->c.red=c.red;
	fig->c.green=c.green;
	fig->c.blue=c.blue;
}
void draw_fx(Figure * fig, double f(double x), double start_x, double end_x,double step_size){
	Point2D *root;
	root=malloc(sizeof(Point2D));
	root->x=start_x;
	root->y=f(start_x);
	root->next=NULL;
	Point2D *iter;
	iter=root;
	
	double i=start_x;
	
	while(i<end_x){
		
		root->next=malloc(sizeof(Point2D));
		root=root->next;
		root->x=i;
		root->y=f(i);
		root->next=NULL;
		i=i+step_size;
		
	}	
	fig->point=iter;
	fig->closepath=0;
	fig->eof=1;
	fig->break_=0;
	
}
void draw_polyline(Figure * fig,Point2D * poly_line, int n){
	int i=0;
	Point2D *iter;
	
	printf("please enter %d. point 'x'\n",i+1);
	scanf("%lf",&poly_line->x);
			
	printf("please enter %d. point 'y'\n",i+1);
	scanf("%lf",&poly_line->y);
	iter=poly_line;
	poly_line->next=NULL;
	for(i=0;i<n;i++){
			
		poly_line->next=malloc(sizeof(Point2D));
		poly_line=poly_line->next;
			
		printf("please enter %d. point 'x'\n",i+2);
		scanf("%lf",&poly_line->x);
			
		printf("please enter %d. point 'y'\n",i+2);
		scanf("%lf",&poly_line->y);
		poly_line->next=NULL;
		
	}
	fig->closepath=0;
	fig->point=iter;
	fig->eof=1;
	fig->break_=0;

}
void draw_polygon(Figure *fig,Point2D * poly_line){
	fig->closepath=1;
	fig->eof=1;
	fig->break_=0;
}

void draw_ellipse(Figure *fig,Point2D * centre, Point2D * width_height){
	/*double i=h+sqrt(pow(a,2)*(1-(pow((y-k),2)/pow(b,2))));*/
	
	double h,k;
	h=centre->x;
	k=centre->y;
	
	double a,b;
	a=width_height->x;
	b=width_height->y;
	double i=centre->x-a;
	

	/*((x-h)^2)/a^2 + ((y-k)^2)/b^2 =1*/
	Point2D *root,*iter;
	
	for(i;i<h+a;i+=0.1){
		if(root==NULL){
			root=malloc(sizeof(Point2D));
			root->x=i;
			root->y=k+sqrt((1-(pow((i-h),2)/pow(a,2)))*pow(b,2));
			root->next=NULL;
			iter=root;
		}
		else{
			iter->next=malloc(sizeof(Point2D));
			iter=iter->next;
			iter->x=i;
			iter->y=k+sqrt((1-(pow((i-h),2)/pow(a,2)))*pow(b,2));
			iter->next=NULL;
		}	
	}
	for(i=centre->x+a;i>h-a;i-=0.1){
		iter->next=malloc(sizeof(Point2D));
		iter=iter->next;
		iter->x=i;
		iter->y=k-sqrt((1-(pow((i-h),2)/pow(a,2)))*pow(b,2));
		iter->next=NULL;
	}

	
	fig->point=root;
	fig->closepath=1;
	fig->break_=0;
	fig->eof=1;

}


void circle_binary_tree(Figure *fig,double x,double y,double size){
	double i;
	
	double a,b;
	
	a=x;
	b=y;
	
	Point2D *iter;
	Point2D *root;
	i=b+4;
	iter=malloc(sizeof(Point2D));
	iter->y=i;
	iter->x=a+sqrt(16-pow((i-b),2));
	iter->next=NULL;
	root=iter;
	
	
	for(i=i-0.1;i>(b-4);i-=0.1){
			
		root->next=malloc(sizeof(Point2D));
		root=root->next;
		root->y=i;
		root->x=a+sqrt(16-pow((i-b),2));
		root->next=NULL;		
	}
	
	for(i=b-4;i<(b+4);i+=0.1){
			
		root->next=malloc(sizeof(Point2D));
		root=root->next;
		root->y=i;
		root->x=a-sqrt(16-pow((i-b),2));
		root->next=NULL;		
	}

	for(i=b+4;i>(b-4);i-=0.1){
			
		root->next=malloc(sizeof(Point2D));
		root=root->next;
		root->y=i;
		root->x=a+sqrt(16-pow((i-b),2));
		root->next=NULL;		
	}
	root->next=malloc(sizeof(Point2D));
	
	root->next->y=root->y-10;
	root->next->x=root->x-size;
	root=root->next;
	root->next=NULL;

	root->next=malloc(sizeof(Point2D));
	root->next->y=b-4;
	root->next->x=a;
	root=root->next;
	root->next=NULL;

	root->next=malloc(sizeof(Point2D));
	root->next->y=root->y-10;
	root->next->x=root->x+size;
	root=root->next;
	root->next=NULL;

	
	fig->point=iter;
	fig->closepath=0;
}


void draw_binary_tree(Figure *fig,Tree * root){
	int x,y;
	char file_name[30];
	x=10;
	y=10;
	int count=0;
	double size=96;
	fig->closepath=0;
	fig->eof=0;
	fig->break_=0;
	printf("PLEASE ENTRE THE BİNARY TREE FİLE NAME ---->""deneme.eps""\n");
	scanf("%s",file_name);
	dolas_prefix(fig,root,x,y,&count,size,file_name);
}




void dolas_prefix(Figure *fig,Tree *root,double x,double y,int *count,double size,char *file_name){
	
	
	if(root==NULL){
		return;
	}
	
	circle_binary_tree(fig,x,y,size);
	export_eps(fig,file_name);
	FILE *fp;
	fp=fopen(file_name,"a");
	fprintf(fp,"\n%%!\n%lf %lf moveto\n/Symbol 4 selectfont (%d) \n",x+(fig->width/2)-3,y+(fig->height/2)-1,root->data);
	fprintf(fp,"show\n");
	fclose(fp);
	dolas_prefix(fig,root->right,(x+size),y-18,count,size-36,file_name);

	dolas_prefix(fig,root->left,(x-size),y-18,count,size-36,file_name);

}


void scale_figure(Figure *fig,double scale_x, double scale_y){
	Point2D *root,*iter;
	root=fig->point;
	iter=root;
	while(root!=NULL){
		root->x=scale_x*root->x;
		root->y=scale_y*root->y;
		root=root->next;

	}
	fig->point=iter;
}

void resize_figure(Figure *fig,Point2D *start_roi, Point2D *end_roi){
	fig->llx=start_roi->x;
	fig->lly=start_roi->y;

	fig->width=end_roi->x;
	fig->height=end_roi->y;
}

void append_figures(Figure * fig1, Figure * fig2){
	int i;
	Point2D *root,*iter;
	root=fig1->point;
	iter=root;
	for(i=0;root->next!=NULL;i++){
		i++;
		root=root->next;
	}
	root->next=fig2->point;
	fig1->point=iter;
	fig1->break_=i;
	fig1->eof=1;
	if(fig1->closepath==1 && fig2->closepath==1){
		fig1->closepath=-1;
	}
	else if(fig1->closepath==0 && fig2->closepath==1){
		fig1->closepath=-2;
	}
	else if(fig1->closepath==1 && fig2->closepath==2){
		fig1->closepath=-3;
	}
	else{
		fig1->closepath=-4;
	}

}


void export_eps(Figure * fig, char * file_name){
	FILE *fp;
	Point2D *p;
	fp=fopen(file_name,"a");
	int i;
	if(fig->break_>0){
		fprintf(fp,"%%!PS-Adobe-3.0 EPSF-3.0");
		fprintf(fp,"\n%%%%BoundingBox: %lf %lf %lf %lf",fig->llx,fig->lly,fig->width,fig->height);

	
		fprintf(fp,"\n%.1lf %.1lf %.1lf  setrgbcolor",fig->c.red,fig->c.green,fig->c.blue);
		fprintf(fp,"\n%lf setlinewidth",fig->thickness);
		p=fig->point;
		fprintf(fp,"\n%.1lf %.1lf moveto\n",p->x+(fig->width/2),p->y+(fig->height/2));
		p=p->next;
		for(i=0;i<fig->break_-3;i++){
			
			fprintf(fp,"%.1lf %.1lf lineto ",p->x+(fig->width/2),p->y+(fig->height/2));
			p=p->next;

		}
		if(fig->closepath==-1 || fig->closepath==-3){
			fprintf(fp," closepath");
		}	
		fprintf(fp,"\nstroke");

		
		fprintf(fp,"\n%.1lf %.1lf moveto\n",p->x+(fig->width/2),p->y+(fig->height/2));
		while(p!=NULL){
			
			fprintf(fp,"%.1lf %.1lf lineto ",p->x+(fig->width/2),p->y+(fig->height/2));
			p=p->next;
		}
		
		if(fig->closepath==-1 || fig->closepath==-2){
			fprintf(fp," closepath");
		}
		fprintf(fp,"\nstroke");

		fprintf(fp,"\n%%%%EOF");
		fclose(fp);
		return ;
	}

	

	fprintf(fp,"%%!PS-Adobe-3.0 EPSF-3.0");
	fprintf(fp,"\n%%%%BoundingBox: %lf %lf %lf %lf",fig->llx,fig->lly,fig->width,fig->height);

	
	fprintf(fp,"\n%.1lf %.1lf %.1lf  setrgbcolor",fig->c.red,fig->c.green,fig->c.blue);
	fprintf(fp,"\n%lf setlinewidth",fig->thickness);
	
	p=fig->point;
	fprintf(fp,"\n%.1lf %.1lf moveto\n",p->x+(fig->width/2),p->y+(fig->height/2));
	p=p->next;
	while(p!=NULL){
		
		fprintf(fp,"%.1lf %.1lf lineto ",p->x+(fig->width/2),p->y+(fig->height/2));
		p=p->next;
	}
	if(fig->closepath==1){
		fprintf(fp,"closepath");
	}

	fprintf(fp,"\nstroke");
	if(fig->eof==1){
		fprintf(fp,"\n%%%%EOF");
	}
	
	fclose(fp);

}