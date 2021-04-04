#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"
char **read_commands(char **informations){
	char ch;
	int i=0,j=0;
	int row;
	FILE *fp;
	fp=fopen("./implementation/commands.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		
		if(ch=='\n'){
			informations[i]=realloc(informations[i],sizeof(char)*(j+1));
			informations[i][j]='\0';
			i++;
			informations=realloc(informations,sizeof(char*)*(i+1));
			
			j=0;
			continue;
		}
		
		informations[i]=realloc(informations[i],sizeof(char)*(j+1));
		informations[i][j]=ch;
		j++;
	}
	fclose(fp);

	informations=realloc(informations,sizeof(char*)*i);
	informations[i-1]=realloc(informations[i-1],sizeof(char));
	informations[i-1][0]='\0';
	
	for(i=0;informations[i][0]!='\0';i++){
		
	}
	row=i;
	for(i=0;i<row;i++){
		for(j=0;informations[i][j]!='\0';j++){
			if(informations[i][j]=='/'){
				informations[i][j]='\0';
				break;
			}
		}
	}
	return informations;

	
}
char **read_defaults(char **informations_defaults){
	char ch;
	int i=0,j=0;
	int row;
	FILE *fp;
	fp=fopen("./implementation/defaults.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		
		if(ch=='\n'){
			informations_defaults[i]=realloc(informations_defaults[i],sizeof(char)*(j+1));
			informations_defaults[i][j]='\0';
			i++;
			informations_defaults=realloc(informations_defaults,sizeof(char*)*(i+1));
			
			j=0;
			continue;
		}
		
		informations_defaults[i]=realloc(informations_defaults[i],sizeof(char)*(j+1));
		informations_defaults[i][j]=ch;
		j++;
	}
	fclose(fp);
	informations_defaults=realloc(informations_defaults,sizeof(char*)*i);
	informations_defaults[i-1]=realloc(informations_defaults[i-1],sizeof(char));
	informations_defaults[i-1][0]='\0';
	
	for(i=0;informations_defaults[i][0]!='\0';i++){
	}
	
	row=i;
	for(i=0;i<row;i++){
		for(j=0;informations_defaults[i][j]!='\0';j++){
			if(informations_defaults[i][j]=='/'){
				informations_defaults[i][j]='\0';
				break;
			}
		}
	}

	return informations_defaults;
}
int control_error(char *informations){
	int count=0;
	int i;
	for(i=0;informations[i]!='\0';i++){
			if (strncmp (informations+i,"archetype",8) ==0){
				count++;
							
    		}
    		if(strncmp (informations+i,"file_name",8) ==0){
    			count++;
    		}
    }
    return count;
}

void store_struct(node *root,char *informations,char **informations_defaults,int count){
	int n,i,j,x=26;
	int control_commands_default[10];
	char *ptr;
	for(i=0;i<10;i++){
		control_commands_default[i]=0;
	}
	for(i=0;informations[i]!='\0';i++){
		
		if (strncmp (informations+i,"archetype",8) ==0){
			if(informations[i+10]=='H'){
				root[count].archetype=6;
			}
			if(informations[i+10]=='S'){
				root[count].archetype=4;
			}
						
   		}
   		
		if (strncmp (informations+i,"file_name",8)==0){
			for(n=i;informations[n]!='\0';n++){
				if(strncmp (informations+n+10,".eps",4)==0){
					break;
				}
			}
			
			strcpy(root[count].name,"./implementation/eps_file/");
			for(j=i+10;j<n+14;j++){
				root[count].name[x]=informations[j];
				x++;
			}
			root[count].name[x]='\0';			
   		}
   		
		if (strncmp (informations+i,"background_color",14) ==0){
			control_commands_default[0]=1;
			root[count].background_color[0]=strtod((informations+i+18),&ptr);
			root[count].background_color[1]=strtod(ptr+1,&ptr);
			root[count].background_color[2]=strtod(ptr+1,&ptr);
   		}

		if (strncmp (informations+i,"foreground_color",14) ==0){
			control_commands_default[1]=1;
			root[count].foreground_color[0]=strtod((informations+i+18),&ptr);
			root[count].foreground_color[1]=strtod(ptr+1,&ptr);
			root[count].foreground_color[2]=strtod(ptr+1,&ptr);
   		}
   		
		if (strncmp (informations+i,"angle_offset",10) ==0){
			control_commands_default[2]=1;
			root[count].angle_offset[0]=strtod((informations+i+14),&ptr);
			root[count].angle_offset[1]=strtod(ptr+1,&ptr);
		}
		
		if (strncmp (informations+i,"canvas_size",10) ==0){
			control_commands_default[3]=1;
			root[count].canvas_size[0]=strtod((informations+i+13),&ptr);
			root[count].canvas_size[1]=strtod(ptr+1,&ptr);
		}
		if (strncmp (informations+i,"show_grid",8) ==0){
			control_commands_default[4]=1;
			if(informations[i+10]=='T'){
				root[count].show_grid=1;
			}
			if(informations[i+10]=='F'){
				root[count].show_grid=0;
			}
		}
		if (strncmp (informations+i,"pattern_thickness",10) ==0){
			control_commands_default[5]=1;
			root[count].pattern_thickness=strtod((informations+i+18),&ptr);		
		}
		
		if (strncmp (informations+i,"grid_color",9) ==0){
			control_commands_default[6]=1;
			root[count].grid_color[0]=strtod((informations+i+12),&ptr);
			root[count].grid_color[1]=strtod(ptr+1,&ptr);
			root[count].grid_color[2]=strtod(ptr+1,&ptr);
   		}
   		if (strncmp (informations+i,"grid_thickness",12) ==0){
			control_commands_default[7]=1;
			root[count].grid_thickness=strtod((informations+i+15),&ptr);		
		}
		if (strncmp (informations+i,"tile_size",9) ==0){
			control_commands_default[8]=1;	
			root[count].tile_size=strtod((informations+i+10),&ptr);

		}

	}
	store_struct_defaults(root,informations_defaults,control_commands_default,count);
}
void store_struct_defaults(node *root,char **informations_defaults,int array[10],int count){
	int i,j;
	char *ptr;
	for(i=0;informations_defaults[i][0]!='\0';i++){
		for(j=0;informations_defaults[i][j]!='\0';j++){
			if (strncmp (informations_defaults[i]+j,"background_color",14) ==0 && array[0]==0){
				root[count].background_color[0]=strtod((informations_defaults[i]+j+18),&ptr);
				root[count].background_color[1]=strtod(ptr+1,&ptr);
				root[count].background_color[2]=strtod(ptr+1,&ptr);
   			}
			if (strncmp (informations_defaults[i]+j,"foreground_color",14) ==0 && array[1]==0){
				root[count].foreground_color[0]=strtod((informations_defaults[i]+j+18),&ptr);
				root[count].foreground_color[1]=strtod(ptr+1,&ptr);
				root[count].foreground_color[2]=strtod(ptr+1,&ptr);
   			}
			if (strncmp (informations_defaults[i]+j,"angle_offset",10) ==0 && array[2]==0){
				root[count].angle_offset[0]=strtod((informations_defaults[i]+j+14),&ptr);
				root[count].angle_offset[1]=strtod(ptr+1,&ptr);

   			}
			if (strncmp (informations_defaults[i]+j,"canvas_size",10) ==0 && array[3]==0){
				root[count].canvas_size[0]=strtod((informations_defaults[i]+j+13),&ptr);
				root[count].canvas_size[1]=strtod(ptr+1,&ptr);

   			}
			if (strncmp (informations_defaults[i]+j,"show_grid",8) ==0 && array[4]==0){
				if(informations_defaults[i][j+10]=='T'){
					root[count].show_grid=1;
				}
				if(informations_defaults[i][j+10]=='F'){
					root[count].show_grid=0;
				}

   			}
			if (strncmp (informations_defaults[i]+j,"pattern_thickness",10) ==0 && array[5]==0){
				root[count].pattern_thickness=strtod((informations_defaults[i]+j+18),&ptr);
   			}
			if (strncmp (informations_defaults[i]+j,"grid_color",9) ==0 && array[6]==0){
				root[count].grid_color[0]=strtod((informations_defaults[i]+j+12),&ptr);
				root[count].grid_color[1]=strtod(ptr+1,&ptr);
				root[count].grid_color[2]=strtod(ptr+1,&ptr);
   			}
			if (strncmp (informations_defaults[i]+j,"grid_thickness",12) ==0 && array[7]==0){
				root[count].grid_thickness=strtod((informations_defaults[i]+j+15),&ptr);
   			}
   			if (strncmp (informations_defaults[i]+j,"tile_size",9) ==0 && array[8]==0){	
					root[count].tile_size=strtod((informations_defaults[i]+j+10),&ptr);		
   			}

		}	
	}
}
void print_square(node *root,int count){
	double i,j;
	double x,x_2;
	double y,y_2;
	double m1,m2;
	double uzunluk;
	double point_x1,point_x2;
	double point_y1,point_y2;
	FILE *fp;
	fp=fopen(root[count].name,"w");
	fprintf(fp,"%%!PS-Adobe-3.0 EPSF-3.0");
	fprintf(fp,"\n%%%%BoundingBox: %d %d %lf %lf",0,0,root[count].canvas_size[0],root[count].canvas_size[1]);
	fprintf(fp,"\n%lf setlinewidth",root[count].grid_thickness);
	fprintf(fp,"\n%lf %lf %lf setrgbcolor",root[count].background_color[0]*1/256,root[count].background_color[1]*1/256,root[count].background_color[2]*1/256);
	fprintf(fp,"\n%d %d moveto\n",0,0);
	fprintf(fp,"%lf %lf lineto ",root[count].canvas_size[0],i);
	fprintf(fp,"%lf %lf lineto ",root[count].canvas_size[0],root->canvas_size[1]);
	fprintf(fp,"%lf %lf lineto ",0.0,root[count].canvas_size[1]);
	fprintf(fp,"closepath fill stroke");
	
	if(root[count].show_grid==1){
		fprintf(fp,"\n%lf setlinewidth",root[count].grid_thickness);
		fprintf(fp,"\n%lf %lf %lf setrgbcolor",root[count].grid_color[0]*1/256,root[count].grid_color[1]*1/256,root[count].grid_color[2]*1/256);
		for(i=0;i<=root[count].canvas_size[1];i+=root[count].tile_size){
			fprintf(fp,"\n%d %lf moveto\n",0,i);
			fprintf(fp,"%lf %lf lineto\n",root[count].canvas_size[0],i);
			fprintf(fp,"stroke");
		}
		for(i=0;i<=root[count].canvas_size[1];i+=root[count].tile_size){
			fprintf(fp,"\n%lf %d moveto\n",i,0);
			fprintf(fp,"%lf %lf lineto\n",i,root[count].canvas_size[0]);
			fprintf(fp,"stroke");
		}
	}
	fprintf(fp,"\n%lf setlinewidth",root[count].pattern_thickness);
	fprintf(fp,"\n%lf %lf %lf setrgbcolor",root[count].foreground_color[0]*1/256,root[count].foreground_color[1]*1/256,root[count].foreground_color[2]*1/256);
	x=(root[count].tile_size/2) - (root[count].angle_offset[1]/2);
	x_2=root[count].tile_size;
	double count_ray;
	m1=(0.5+root[count].angle_offset[0])*3.141818/180;
	m1=tan(m1);
	m2=(89.5-root[count].angle_offset[0])*3.141818/180;
	m2=tan(m2);

	x=0;
	point_x1=(root[count].tile_size/2) - (root[count].angle_offset[1]/2);//41
	point_y1=0;//
	point_x2=root[count].tile_size;//100
	point_y2=(root[count].tile_size/2) + (root[count].angle_offset[1]/2);//55
	i=0;//sütun
	
	while(1){
		y=((x-point_x1)*m1);
		y_2=(m2*(x-point_x2))+point_y2;
				
		if(fabs(y-y_2)<0.01){
					
			for(j=0;j<root[count].canvas_size[0];j+=root[count].tile_size){	
				for(i=0;i<root[count].canvas_size[0];i+=root[count].tile_size){	
					fprintf(fp,"\n%lf %lf moveto\n",(root[count].tile_size/2) - (root[count].angle_offset[1]/2)+i,j);
					fprintf(fp,"%lf %lf lineto\n",x+i,y_2+j);
					fprintf(fp,"%lf %lf lineto\n",point_x2+i,point_y2+j);
					fprintf(fp,"stroke");

					fprintf(fp,"\n%lf %lf moveto\n",(root[count].tile_size/2) - (root[count].angle_offset[1]/2)+i,root[count].tile_size+j);
					fprintf(fp,"%lf %lf lineto\n",x+i,(root[count].tile_size-y_2)+j);
					fprintf(fp,"%lf %lf lineto\n",point_x2+i,root[count].tile_size-point_y2+j);
					fprintf(fp,"stroke");
				}
			}

			break;
		}
		x+=0.0001;
	}
	m1=(0.5+root[count].angle_offset[0])*3.141818/180;
	m1=-tan(m1);
				
	m2=(89.5-root[count].angle_offset[0])*3.141818/180;
	m2=-tan(m2);
			
	x=0;
	point_x1=(root[count].tile_size/2) + (root[count].angle_offset[1]/2);//41
	point_y1=0;//
	point_x2=0;//100
	point_y2=(root[count].tile_size/2) + (root[count].angle_offset[1]/2);
	while(1){
		y=((x-point_x1)*m1);
		y_2=(m2*(x-point_x2))+point_y2;
				
		if(fabs(y-y_2)<0.01){
			for(j=0;j<root[count].canvas_size[0];j+=root[count].tile_size){	
				for(i=0;i<root[count].canvas_size[0];i+=root[count].tile_size){						

					fprintf(fp,"\n%lf %lf moveto\n",(root[count].tile_size/2) + (root[count].angle_offset[1]/2)+i,j);
					fprintf(fp,"%lf %lf lineto\n",x+i,y_2+j);
					fprintf(fp,"%lf %lf lineto\n",point_x2+i,point_y2+j);
					fprintf(fp,"stroke");

					fprintf(fp,"\n%lf %lf moveto\n",(root[count].tile_size/2) + (root[count].angle_offset[1]/2)+i,root[count].tile_size+j);
					fprintf(fp,"%lf %lf lineto\n",x+i,(root[count].tile_size)-y_2+j);
					fprintf(fp,"%lf %lf lineto\n",point_x2+i,root[count].tile_size-point_y2+j);
					fprintf(fp,"stroke");
				}
			}

			break;
		}
		x+=0.0001;
	}	
	fprintf(fp,"\n%%%%EOF");
	fclose(fp);

}
void print_hexagon(node *root,int count){

	FILE *fp;
	double i=0,j;
	double x,y;
	double m1,m2;
	double x_2,y_2;
	double point_x1,point_y1;
	double x_3,y_3;
	double point_x2,point_y2;
	double count1,count2;
	fp=fopen(root[count].name,"w");
	fprintf(fp,"%%!PS-Adobe-3.0 EPSF-3.0");
	fprintf(fp,"\n%%%%BoundingBox: %d %d %lf %lf",0,0,root[count].canvas_size[0],root[count].canvas_size[1]);
	fprintf(fp,"\n%lf setlinewidth",root[count].grid_thickness);
	fprintf(fp,"\n%lf %lf %lf setrgbcolor",root[count].background_color[0]*1/256,root[count].background_color[1]*1/256,root[count].background_color[2]*1/256);
	fprintf(fp,"\n%d %d moveto\n",0,0);
	fprintf(fp,"%lf %lf lineto ",root[count].canvas_size[0],i);
	fprintf(fp,"%lf %lf lineto ",root[count].canvas_size[0],root[count].canvas_size[1]);
	fprintf(fp,"%lf %lf lineto ",0.0,root[count].canvas_size[1]);
	fprintf(fp,"closepath fill stroke");
	if(root[count].show_grid==1){
		fprintf(fp,"\n%lf setlinewidth",root[count].grid_thickness);
		fprintf(fp,"\n%lf %lf %lf setrgbcolor",root[count].grid_color[0]*1/256,root[count].grid_color[1]*1/256,root[count].grid_color[2]*1/256);
		x=root[count].tile_size*sqrt(3);
		y=2*root[count].tile_size;
	
		for(j=0;j<=root[count].canvas_size[1]+y;j+=y/2+y){
			for(i=0;i<=root[count].canvas_size[0]+x;i+=x){
				fprintf(fp,"\n%lf %lf moveto\n",0.0+i,y/2+j);
				fprintf(fp,"%lf %lf lineto ",x/2+i,y/4+j);
				fprintf(fp,"%lf %lf lineto ",x/2+i,-y/4+j);
				fprintf(fp,"%lf %lf lineto ",0.0+i,-y/2+j);
				fprintf(fp,"%lf %lf lineto ",-x/2+i,-y/4+j);
				fprintf(fp,"%lf %lf lineto ",-x/2+i,y/4+j);
				fprintf(fp,"closepath stroke");
			}
		}
		for(j=0;j<=root[count].canvas_size[1]+y;j+=y/2+y){
			for(i=0;i<=root[count].canvas_size[0]+x;i+=x){
				fprintf(fp,"\n%lf %lf moveto\n",x/2+i,y+y/4+j);
				fprintf(fp,"%lf %lf lineto ",x+i,y+j);
				fprintf(fp,"%lf %lf lineto ",x+i,y/2+j);
				fprintf(fp,"%lf %lf lineto ",x/2+i,y/4+j);
				fprintf(fp,"%lf %lf lineto ",0.0+i,y/2+j);
				fprintf(fp,"%lf %lf lineto ",0.0+i,y+j);
				fprintf(fp,"closepath stroke");
			}
		}
	}
	x=root[count].tile_size*sqrt(3);
	y=2*root[count].tile_size;
	
	m1=(330.1+root[count].angle_offset[0])*3.141818/180;
	m1=tan(m1);

	point_y1=(((y/4)+(root[count].angle_offset[1]/2))/(y/2)*(y/4))-(y/2);

	point_x1=-(((y/4)+(root[count].angle_offset[1]/2))/(y/2))*(x/2);
	x_2=0;
	y_2=point_y1+m1*(x_2-point_x1);	
	
	m2=(31-root[count].angle_offset[0])*3.141818/180;
	x_3=0;
	y_3=(m2*(x_2-point_x1)-point_y1);
	fprintf(fp,"\n%lf setlinewidth",root[count].pattern_thickness);
	fprintf(fp,"\n%lf %lf %lf setrgbcolor",root[count].foreground_color[0]*1/256,root[count].foreground_color[1]*1/256,root[count].foreground_color[2]*1/256);
	
	for(j=0;j<=root[count].canvas_size[1]+y;j+=y/2+y){
		for(i=0;i<=root[count].canvas_size[0]+x;i+=x){
			fprintf(fp,"\n%lf %lf moveto\n",point_x1+i,point_y1+j);
			fprintf(fp,"%lf %lf lineto ",x_2+i,y_2+j);
			fprintf(fp,"%lf %lf lineto\n",-point_x1+i,point_y1+j);
			fprintf(fp,"stroke");

			fprintf(fp,"\n%lf %lf moveto\n",point_x1+i,(-point_y1+j));
			fprintf(fp,"%lf %lf lineto ",x_2+i,y_3+j);
			fprintf(fp,"%lf %lf lineto\n",-point_x1+i,(-point_y1+j));
			fprintf(fp,"stroke");
			
			fprintf(fp,"\n%lf %lf moveto\n",point_x1+i+x/2,point_y1+j+(3*(y/4)));
			fprintf(fp,"%lf %lf lineto ",x_2+i+x/2,y_2+j+(3*(y/4)));
			fprintf(fp,"%lf %lf lineto\n",-point_x1+i+x/2,point_y1+j+(3*(y/4)));
			fprintf(fp,"stroke");

			fprintf(fp,"\n%lf %lf moveto\n",point_x1+i+x/2,-point_y1+j+(3*(y/4)));
			fprintf(fp,"%lf %lf lineto ",x_2+i+x/2,y_3+j+(3*(y/4)));
			fprintf(fp,"%lf %lf lineto\n",-point_x1+i+x/2,-point_y1+j+(3*(y/4)));
			fprintf(fp,"stroke");
		}
	}

	
x=root[count].tile_size*sqrt(3);
	y=2*root[count].tile_size;



	point_x1=-(x/2);
	point_y1=root[count].angle_offset[1]/2;

	point_x2=-((((y/4)-(root[count].angle_offset[1]/2))/(y/2))*(x/2));

	point_y2=(((y/4)-(root[count].angle_offset[1]/2))/(y/2))*(y/4);
	point_y2=-((y/2)-point_y2);

	
	m1=(91+root[count].angle_offset[0])*3.141818/180;
	m1=tan(m1);

	m2=(149-root[count].angle_offset[0])*3.141818/180;
	m2=tan(m2);
	i=-x;
	while(1){
		y_2=point_y1+(m1*(i-point_x1));
		y_3=point_y2+(m2*(i-point_x2));
		
		if(fabs(y_2-y_3)<0.5){
			for(count2=0;count2<root[count].canvas_size[1]+y;count2+=y+y/2){	
				for(count1=0;count1<root[count].canvas_size[0]+x;count1+=x){
					fprintf(fp,"\n%lf %lf moveto\n",point_x1+count1,point_y1+count2);
					fprintf(fp,"%lf %lf lineto\n",i+count1,y_2+count2);
					fprintf(fp,"%lf %lf lineto\n",point_x2+count1,point_y2+count2);
					fprintf(fp,"stroke");

					fprintf(fp,"\n%lf %lf moveto\n",point_x1+count1-x/2,point_y1+count2-(3*y/4));
					fprintf(fp,"%lf %lf lineto\n",i+count1-x/2,y_2+count2-(3*y/4));
					fprintf(fp,"%lf %lf lineto\n",point_x2+count1-x/2,point_y2+count2-(3*y/4));
					fprintf(fp,"stroke");
				

				}	
					
			}
			break;
		}	
		i+=0.001;
	}
	point_x1=x/2;
	point_y1=root[count].angle_offset[1]/2;

	point_x2=((((y/4)-(root[count].angle_offset[1]/2))/(y/2))*(x/2));

	point_y2=(((y/4)-(root[count].angle_offset[1]/2))/(y/2))*(y/4);
	point_y2=-((y/2)-point_y2);		
		
	for(count2=0;count2<root[count].canvas_size[1]+y;count2+=y+y/2){	
		for(count1=0;count1<root[count].canvas_size[0]+x;count1+=x){
			fprintf(fp,"\n%lf %lf moveto\n",point_x1+count1,point_y1+count2);
			fprintf(fp,"%lf %lf lineto\n",-i+count1,y_2+count2);
			fprintf(fp,"%lf %lf lineto\n",point_x2+count1,point_y2+count2);
			fprintf(fp,"stroke");

			fprintf(fp,"\n%lf %lf moveto\n",point_x1+count1-x/2,point_y1+count2-(3*y/4));
			fprintf(fp,"%lf %lf lineto\n",-i+count1-x/2,y_2+count2-(3*y/4));
			fprintf(fp,"%lf %lf lineto\n",point_x2+count1-x/2,point_y2+count2-(3*y/4));
			fprintf(fp,"stroke");
		}	
	}
	point_x1=-(x/2);
	point_y1=-root[count].angle_offset[1]/2;

	point_x2=-((((y/4)-(root[count].angle_offset[1]/2))/(y/2))*(x/2));
	point_y2=(((y/4)-(root[count].angle_offset[1]/2))/(y/2))*(y/4);
	point_y2=((y/2)-point_y2);
			
	for(count2=0;count2<root[count].canvas_size[1]+y;count2+=y+y/2){	
		for(count1=0;count1<root[count].canvas_size[0]+x;count1+=x){
			fprintf(fp,"\n%lf %lf moveto\n",point_x1+count1,point_y1+count2);
			fprintf(fp,"%lf %lf lineto\n",i+count1,-y_2+count2);
			fprintf(fp,"%lf %lf lineto\n",point_x2+count1,point_y2+count2);
			fprintf(fp,"stroke");

			fprintf(fp,"\n%lf %lf moveto\n",point_x1+count1-x/2,point_y1+count2-(3*y/4));
			fprintf(fp,"%lf %lf lineto\n",i+count1-x/2,-y_2+count2-(3*y/4));
			fprintf(fp,"%lf %lf lineto\n",point_x2+count1-x/2,point_y2+count2-(3*y/4));
			fprintf(fp,"stroke");
				

		}	
					
	}
	point_x1=+(x/2);
	point_y1=-root[count].angle_offset[1]/2;

	point_x2=(((y/4)-(root[count].angle_offset[1]/2))/(y/2))*(x/2);

	point_y2=(((y/4)-(root[count].angle_offset[1]/2))/(y/2))*(y/4);
	point_y2=((y/2)-point_y2);

	
		
		
	for(count2=0;count2<root[count].canvas_size[1]+y;count2+=y+y/2){	
		for(count1=0;count1<root[count].canvas_size[0]+x;count1+=x){
			fprintf(fp,"\n%lf %lf moveto\n",point_x1+count1,point_y1+count2);
			fprintf(fp,"%lf %lf lineto\n",-i+count1,-y_2+count2);
			fprintf(fp,"%lf %lf lineto\n",point_x2+count1,point_y2+count2);
			fprintf(fp,"stroke");

			fprintf(fp,"\n%lf %lf moveto\n",point_x1+count1-x/2,point_y1+count2-(3*y/4));
			fprintf(fp,"%lf %lf lineto\n",-i+count1-x/2,-y_2+count2-(3*y/4));
			fprintf(fp,"%lf %lf lineto\n",point_x2+count1-x/2,point_y2+count2-(3*y/4));
			fprintf(fp,"stroke");
				

		}	
					
	}

	fprintf(fp,"\n%%%%EOF");
	fclose(fp);

}
