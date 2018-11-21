//#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


//GLfloat angle, fAspect;
GLfloat ASPECTO, ANGULO;
int x_ini,y_ini, bot;
GLfloat obsX, obsY, obsZ, rotX, rotY;
GLfloat obsX_ini, obsY_ini, obsZ_ini, rotX_ini, rotY_ini;
GLfloat escalaX, escalaY, escalaZ;
#define SENS_ROT 10.0
#define SENS_OBS 10.0
#define SENS_TRANS 10.0   

	// date class 05-11-18
	static int slices = 40;
	static int stacks = 40;
	static double t = 0;
	static double a = 0;
	static double angPorta 	= 0;
	static double transJ 	= 19;
	static double transJ2 	= 25;
	static double transJ3 	= 24;
	static double transJ4 	= 18;
	
	static bool flagS = false;
	static bool flagT = false;
	static bool flagC = false;
	
	GLUquadricObj *quadratic;
	
	//date class 05-11-18
	static void idle(void){
		t = glutGet(GLUT_ELAPSED_TIME) / 1000.0; 	//tempo randomico  {quanto maior mais devagar}
		a = t*90.0;									//angulo randomico 				
		
		// Abrir portas
		if(flagS && angPorta < 90) 
		{
			angPorta += 0.5;
		}
		
		// Fechar portas
		if(!flagS && angPorta > 0)
		{
			angPorta -= 0.5;
		}
		
		// Abrir Janelas 1 e 2
		if(flagT && (transJ>=18 || transJ2>=24))
		{
			transJ 	-= 0.001;
			transJ2 -= 0.001;
		}
		
		
		glutPostRedisplay();
	}

	// função teclado, recebendo informação para as portas e janelas
static void 
key(unsigned char key, int x, int y)
{
    switch (key) 
    {
        case 27 : 
        case 'q':
            exit(0);
            break;

        case 'p':
        	if(!flagS){
            	flagS = true;
            }
            break;

        case 'f':
            if (flagS)
            {
                flagS = false;
            }
            break;       
		 
        case 'j':
        	/*if(transJ>=18 || transJ2 >= 24 || transJ3 <= 25 || transJ4 <= 19)
			{
				transJ 	-= 0.1;		
				transJ2 -= 0.1;
				transJ3 += 0.1;
				transJ4 += 0.1;
			}*/
			if(!flagT)
			{
				flagT = true;
			}				
			break;
		case 'w':
			if(transJ<19 || transJ2 < 25 || transJ3 > 24 || transJ4 > 18)
			{
				transJ 	+= 0.1;
				transJ2 += 0.1;
				transJ3 -= 0.1;
				transJ4 -= 0.1;
			}
			break;
    }
    glutPostRedisplay();
}

	
// Função callback chamada para fazer o desenho
void Desenha(void)
{
	// Limpa a janela e o depth buffer
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 glClear(GL_COLOR_BUFFER_BIT);
    
    	
/*
		glPushMatrix();
            glColor3f(0.9, 0.9, 0.9);
            glBegin(GL_LINES);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(0.0, 300.0, 0.0);
            glEnd(); 
	    glPopMatrix();
     
		glPushMatrix();
            glColor3f(0.9, 0.9, 0.9);
            glBegin(GL_LINES);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(300.0, 0.0, 0.0);
            glEnd(); 
	    glPopMatrix();
		
		glPushMatrix();
            glColor3f(0.9, 0.9, 0.9);
            glBegin(GL_LINES);
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(0.0, 0.0, 300.0);
            glEnd(); 
	    glPopMatrix();
  
	    glPushMatrix();
            glColor3f(1.0, 0.0, 0.0);
            glTranslatef(10,0.0,0.0);
            glutSolidSphere(1.0,50.0,50.0);
	    glPopMatrix();  		
  */	

// AULA DE IERARQUIA
/*
  	  	  // MATRIZ 1
  		glPushMatrix(); 	// 1
  			glLineWidth(50.0f);
  		
  			// ombro (bola)
  			glColor3f(1.0,0.0,0.0);
  			glutSolidSphere(1.0,50.0,50.0); // parametros(tamanho,qtde slices, qtde stack)
  			
  			glRotatef(a,0,0,1); 
  			
			// braço            
			glBegin(GL_LINES);            
	    	glVertex3f(0.0, 0.0, 0.0);
	    	glVertex3f(10.0, 0.0, 0.0);
            glEnd();
            
        	glPushMatrix(); // 2
        		glLineWidth(50.0f);
        		
	            // cotovelo (bola)
				glColor3f(1.0, 0.0, 0.0);
	            glTranslatef(10.0,0.0,0.0);
	            glutSolidSphere(1.0,50.0,50.0);      
	            
	            glRotatef(a,0,0,1);
	            // ante braco
				glBegin(GL_LINES);            
		    	glVertex3f(0.0, 0.0, 0.0);
		    	glVertex3f(10.0, 0.0, 0.0);
	            glEnd();
	            
	            // mao (bola)
	            glColor3f(1.0, 0.0, 0.0);
	            glTranslatef(10.0,0.0,0.0);
	            glutSolidSphere(1.0,50.0,50.0);
        
			glPopMatrix();		// 2
	    glPopMatrix();  	// 1
*/	    


/*
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

*/
// CONSTRUIR CASA A PARTIR DAQUI

		// CILINDRO
		glPushMatrix();
			glTranslatef(20,5,10); 
			glRotatef(90,10,0,0);			
    		glColor3f(1,0,0);    		   		
    		gluCylinder(quadratic, 0.2, 0.2, 5, 30, 30); // base, topo, altura, slices, stacks
    	//glPopMatrix();
    	
		//glPushMatrix();
			glTranslatef(5,0,0); 
			//glRotatef(90,10,0,0);			
    		//glColor3f(1,0,0);    		   		
    		gluCylinder(quadratic, 0.2, 0.2, 5, 30, 30); // base, topo, altura, slices, stacks
    	//glPopMatrix();
    	
		//glPushMatrix();
			glTranslatef(-5,5,0); 
			//glRotatef(90,10,0,0);			
    		//glColor3f(1,0,0);    		   		
    		gluCylinder(quadratic, 0.2, 0.2, 5, 30, 30); // base, topo, altura, slices, stacks
    	//glPopMatrix();
    	
		//glPushMatrix();
			glTranslatef(5,0,0); 
			//glRotatef(90,10,0,0);			
    		//glColor3f(1,0,0);    		   		
    		gluCylinder(quadratic, 0.2, 0.2, 5, 30, 30); // base, topo, altura, slices, stacks
    		
    		
// DESENHANDO MESA NO MESANINO + TEAPOT 
    		glColor3f(0.55,0.27,0.07);
    		glTranslatef(-1,-2,-0.5);
			gluCylinder(quadratic,0.5,0,0,30,30); 		// mesa achatada
			gluCylinder(quadratic,0.2,0.2,0.5,30,30); 	// base da mesa
			glColor3f(0.85,0.65,0.13); 					// dourado chalera
			glTranslatef(0,0,-0.15);
			glRotatef(270,1,0,0);
			glutSolidTeapot(0.2);
			
    	glPopMatrix();
    	
    	// GRAMADO - PISO
    	glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(0,1,0); // verde gramado
				glVertex3f(0,0,0);
				glVertex3f(50,0,0);
				glVertex3f(50,0,50);
				glVertex3f(0,0,50);             
     	 	glEnd();
  	 	glPopMatrix();
  	 	
  	 	// CASA
		glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(0.66,0.66,0.66); // cinza escuro
				glVertex3f(10,0,10);
				glVertex3f(10,6,10);
				glVertex3f(10,6,30);
				glVertex3f(10,0,30);             
     	 	glEnd();     	 	
  	 	glPopMatrix();
  	 	
		glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(0.66,0.66,0.66); // cinza escuro
				glVertex3f(10,8,10);
				glVertex3f(10,10,10);
				glVertex3f(10,10,30);
				glVertex3f(10,8,30);             
     	 	glEnd();
  	 	glPopMatrix();
  	 	
		glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(0.66,0.66,0.66); // cinza escuro
				glVertex3f(15,0,15); 
				glVertex3f(15,6,15);
				glVertex3f(15,6,30);
				glVertex3f(15,0,30);             
     	 	glEnd();
     	 	glBegin(GL_QUADS);
     	 		glVertex3f(15,6,15);
     	 		glVertex3f(15,6,18);
     	 		glVertex3f(15,10,18);
     	 		glVertex3f(15,10,15);
     	 	glEnd();
     	 	glBegin(GL_QUADS);
     	 		glVertex3f(15,6,20);
     	 		glVertex3f(15,6,24);
     	 		glVertex3f(15,10,24);
     	 		glVertex3f(15,10,20);
     	 	glEnd();
     	 	glBegin(GL_QUADS);
     	 		glVertex3f(15,6,26);
     	 		glVertex3f(15,6,30);
     	 		glVertex3f(15,10,30);
     	 		glVertex3f(15,10,26);
     	 	glEnd();
     	 	glBegin(GL_QUADS);
     	 		glVertex3f(10,6,10);
     	 		glVertex3f(10,6,18);
     	 		glVertex3f(10,10,18);
     	 		glVertex3f(10,10,10);
     	 	glEnd();
     	 	glBegin(GL_QUADS);
     	 		glVertex3f(10,6,20);
     	 		glVertex3f(10,6,24);
     	 		glVertex3f(10,10,24);
     	 		glVertex3f(10,10,20);
     	 	glEnd();
     	 	glBegin(GL_QUADS);
     	 		glVertex3f(10,6,26);
     	 		glVertex3f(10,6,30);
     	 		glVertex3f(10,10,30);
     	 		glVertex3f(10,10,26);
     	 	glEnd();
  	 	glPopMatrix();	 	
  	 	
		glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(0.66,0.66,0.66); // cinza escuro
				glVertex3f(15,8,15);
				glVertex3f(15,10,15);
				glVertex3f(15,10,30);
				glVertex3f(15,8,30);             
     	 	glEnd();
  	 	glPopMatrix();

		glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(0.66,0.66,0.66); // cinza escuro
				glVertex3f(10,0,30);
				glVertex3f(10,10,30);
				glVertex3f(15,10,30);
				glVertex3f(15,0,30);             
     	 	glEnd();
  	 	glPopMatrix();

		glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(0.66,0.66,0.66); // cinza escuro
				glVertex3f(15,8,15);
				glVertex3f(15,10,15);
				glVertex3f(15,10,30);
				glVertex3f(15,8,30);             
     	 	glEnd();
  	 	glPopMatrix();		   
		   
		glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(0.66,0.66,0.66); // cinza escuro
				glVertex3f(10,0,10);
				glVertex3f(10,10,10);
				glVertex3f(20,10,10);
				glVertex3f(20,0,10);             
     	 	glEnd();
  	 	glPopMatrix();
  	 	
		glPushMatrix();
			glBegin(GL_QUADS);
				glColor3f(0.66,0.66,0.66); // cinza escuro
				glVertex3f(15,0,15);
				glVertex3f(15,10,15);
				glVertex3f(20,10,15);
				glVertex3f(20,0,15);             
     	 	glEnd();
  	 	glPopMatrix();
  	 	
		glPushMatrix(); // saida para garagem
			glBegin(GL_QUADS);
				glColor3f(0.66,0.66,0.66); // cinza escuro
				glVertex3f(20,2,10);
				glVertex3f(20,5,10);
				glVertex3f(20,5,15);
				glVertex3f(20,2,15);             
     	 	glEnd();
     	 	glBegin(GL_QUADS);
				glVertex3f(20,7,10);
				glVertex3f(20,10,10);
				glVertex3f(20,10,15);
				glVertex3f(20,7,15); 
			glEnd();
			glBegin(GL_QUADS);
				glVertex3f(20,0,10);
				glVertex3f(20,0,12);
				glVertex3f(20,10,12);
				glVertex3f(20,10,10);
			glEnd();  		
			glBegin(GL_QUADS);
				glVertex3f(20,0,13);
				glVertex3f(20,0,15);
				glVertex3f(20,10,15);
				glVertex3f(20,10,13);
			glEnd();
			glColor3f(0,0,0); // cor das linhas (preta)
			glBegin(GL_LINES);
				// linhas da porta inferior
				glVertex3f(20,0,12);
				glVertex3f(20,2,12);
				glVertex3f(20,2,12);
				glVertex3f(20,2,13);
				glVertex3f(20,2,13);
				glVertex3f(20,0,13);
				// linhas da porta superior
				glVertex3f(20,5,12);
				glVertex3f(20,7,12);
				glVertex3f(20,7,12);
				glVertex3f(20,7,13);
				glVertex3f(20,7,13);
				glVertex3f(20,5,13);
			glEnd();
  	 	glPopMatrix();	 	
  	 	
		   // piso terreo
  	 	glPushMatrix();
  	 		glBegin(GL_POLYGON);
  	 			glColor3f(0.98,0.92,0.84); // branco antigo
  	 			glVertex3f(8,0.1,8);
  	 			glVertex3f(27,0.1,8);
  	 			glVertex3f(27,0.1,17);
  	 			glVertex3f(17,0.1,17);
  	 			glVertex3f(17,0.1,32);
  	 			glVertex3f(8,0.1,32);
  	 		glEnd();
        glPopMatrix();
        
  	 	// piso 2º andar
  	 	glPushMatrix();
  	 		glBegin(GL_POLYGON);
  	 			glColor3f(0.98,0.92,0.84); // branco antigo
  	 			glVertex3f(10,5,10);
  	 			glVertex3f(25,5,10);
  	 			glVertex3f(25,5,15);
  	 			glVertex3f(15,5,15);
  	 			glVertex3f(15,5,30);
  	 			glVertex3f(10,5,30);
  	 		glEnd();
        glPopMatrix();
        
        // forro telhado
  	 	glPushMatrix();
  	 		glBegin(GL_POLYGON);
  	 			glColor3f(0.98,0.92,0.84); // branco antigo
  	 			glVertex3f(10,10,10);
  	 			glVertex3f(20,10,10);
  	 			glVertex3f(20,10,15);
  	 			glVertex3f(15,10,15);
  	 			glVertex3f(15,10,30);
  	 			glVertex3f(10,10,30);
  	 		glEnd();
        glPopMatrix();
        
        // telhado
        glPushMatrix();
        	glBegin(GL_TRIANGLES);
        		glColor3f(0.6,0.4,0.8);
        		glVertex3f(12.5,12.5,28);
        		glVertex3f(17,9.5,30.4);
        		glVertex3f(8,9.5,30.4);
  		    glEnd();
	    glPopMatrix();
	    
        glPushMatrix();
        	glBegin(GL_TRIANGLES);
        		glColor3f(0.6,0.4,0.8); // amertista
        		glVertex3f(17.5,12.5,12.5);
        		glVertex3f(20.5,9.5,8);
        		glVertex3f(20.5,9.5,17);
  		    glEnd();
	    glPopMatrix();
	    
  	 	glPushMatrix();
  	 		glBegin(GL_QUADS);
  	 			glColor3f(0.6,0.4,0.8); // amertista
  	 			glVertex3f(17,9.5,30.4);
  	 			glVertex3f(12.5,12.5,28);
  	 			glVertex3f(12.5,12.5,12.5);
  	 			glVertex3f(17,9.5,17);
  	 		glEnd();
        glPopMatrix();

  	 	glPushMatrix();
  	 		glBegin(GL_QUADS);
  	 			glColor3f(0.6,0.4,0.8); // amertista
  	 			glVertex3f(17.5,12.5,12.5);
  	 			glVertex3f(20.5,9.5,17);
  	 			glVertex3f(17,9.5,17);
  	 			glVertex3f(12.5,12.5,12.5);
  	 		glEnd();
        glPopMatrix();

  	 	glPushMatrix();
  	 		glBegin(GL_QUADS);
  	 			glColor3f(0.6,0.4,0.8); // amertista
  	 			glVertex3f(20.5,9.5,8);
  	 			glVertex3f(17.5,12.5,12.5);
  	 			glVertex3f(12.5,12.5,12.5);
  	 			glVertex3f(8,9.5,8);
  	 		glEnd();
        glPopMatrix();
        
  	 	glPushMatrix();
  	 		glBegin(GL_QUADS);
  	 			glColor3f(0.6,0.4,0.8); // amertista
  	 			glVertex3f(8,9.5,8);
  	 			glVertex3f(12.5,12.5,12.5);
  	 			glVertex3f(12.5,12.5,28);
  	 			glVertex3f(8,9.5,30.4);
  	 		glEnd();
        glPopMatrix();

//	------ PORTAS ----------
        // PORTA a cima da garagem
        glPushMatrix();
        	glTranslatef(20,5,12);
        	glRotatef(angPorta,0,1,0);
        	glBegin(GL_QUADS);
        		glColor3f(0.96,0.64,0.38); // marrom amarelado
        		glVertex3f(0,0,0);
        		glVertex3f(0,0,1);
        		glVertex3f(0,2,1);
        		glVertex3f(0,2,0);
		   glEnd();
        glPopMatrix();
        
        //PORTA da garagem
        glPushMatrix();
        	glTranslatef(20,0,12);
        	glRotatef(angPorta,0,1,0);
  	    	glBegin(GL_QUADS);
   		        glVertex3f(0,0,0);
        		glVertex3f(0,0,1);
        		glVertex3f(0,2,1);
        		glVertex3f(0,2,0);
		   glEnd();
        glPopMatrix();
        

//	------ JANELAS ----------
        // JANELAS
        
        // TORUS - BORDAS DAS JANELAS
        // TORUS JANELA 1
        glPushMatrix();
        	glTranslatef(15,7,19);
        	glRotatef(45,0,0,1); // rotaciona 45º no eixo z
         	glRotatef(90,1,1,0); // rotaciona 90º no eixo x,y
        	glColor3f(0.47,0.53,0.42); //verde militar
        	glutSolidTorus(0.2,1.5,/*slices*/4,/*stacks*/4);
	    glPopMatrix();
	    
	    // TORUS JANELA 2
        glPushMatrix();
        	glTranslatef(15,7,25);
        	glRotatef(45,0,0,1); // rotaciona 45º no eixo z
         	glRotatef(90,1,1,0); // rotaciona 90º no eixo x,y
        	glColor3f(0.47,0.53,0.42); //verde militar
        	glutSolidTorus(0.2,1.5,/*slices*/4,/*stacks*/4);
	    glPopMatrix();
	    
	    // TORUS JANELA 3
        glPushMatrix();
        	glTranslatef(10,7,19);
        	glRotatef(45,0,0,1); // rotaciona 45º no eixo z
         	glRotatef(90,1,1,0); // rotaciona 90º no eixo x,y
        	glColor3f(0.47,0.53,0.42); //verde militar
        	glutSolidTorus(0.2,1.5,/*slices*/4,/*stacks*/4);
	    glPopMatrix();
	    
	    // TORUS JANELA 4
        glPushMatrix();
        	glTranslatef(10,7,25);
        	glRotatef(45,0,0,1); // rotaciona 45º no eixo z
         	glRotatef(90,1,1,0); // rotaciona 90º no eixo x,y
        	glColor3f(0.47,0.53,0.42); //verde militar
        	glutSolidTorus(0.2,1.5,/*slices*/4,/*stacks*/4);
	    glPopMatrix();
        
        // JANELA 1
        
  		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 	
        glPushMatrix(); 
		
  			glColor3f(1,1,1); // Branco 				
        	glBegin(GL_QUADS);       		
        		glVertex3f(15,6,18);
        		glVertex3f(15,6,19);
        		glVertex3f(15,8,19);
        		glVertex3f(15,8,18);
		    glEnd();
			glBegin(GL_LINES);
				glColor3f(0,0,0);
				glVertex3f(15,6,18);
				glVertex3f(15,6,19);
				glVertex3f(15,6,19);
				glVertex3f(15,8,19);
				glVertex3f(15,8,19);
				glVertex3f(15,8,18);
				glVertex3f(15,8,18);
				glVertex3f(15,6,18);
			glEnd();				    
        glPopMatrix();
		
        glPushMatrix();
        	glTranslatef(15,6,transJ); // 15,6,19
        	glBegin(GL_QUADS);
        		glColor3f(1,1,1); // Branco
        		
        		glVertex3f(0,0,0);
        		glVertex3f(0,0,1);
        		glVertex3f(0,2,1);
        		glVertex3f(0,2,0);
		    glEnd();	
			glBegin(GL_LINES);
				glColor3f(0,0,0);
				glVertex3f(0,0,0);
		       	glVertex3f(0,0,1);
		      	glVertex3f(0,0,1);
		       	glVertex3f(0,2,1);
		       	glVertex3f(0,2,1);
		       	glVertex3f(0,2,0);
		       	glVertex3f(0,2,0);
		       	glVertex3f(0,0,0);
			glEnd();    
        glPopMatrix();
        //fim janela 1

		// JANELA 2
        glPushMatrix();
        	glBegin(GL_QUADS);
        		glColor3f(1,1,1); // Branco
        		glVertex3f(15,6,24);
        		glVertex3f(15,6,25);
        		glVertex3f(15,8,25);
        		glVertex3f(15,8,24);
		    glEnd();
		    glBegin(GL_LINES);
   				glColor3f(0,0,0);
				glVertex3f(15,6,24);
				glVertex3f(15,6,25);
				glVertex3f(15,6,25);
				glVertex3f(15,8,25);
				glVertex3f(15,8,25);
				glVertex3f(15,8,24);
				glVertex3f(15,8,24);
				glVertex3f(15,6,24);
            glEnd();
        glPopMatrix();

        glPushMatrix();
        	glTranslatef(15,6,transJ2); //15,6,25
        	glBegin(GL_QUADS);
        		glColor3f(1,1,1); // Branco
        		glVertex3f(0,0,0);
        		glVertex3f(0,0,1);
        		glVertex3f(0,2,1);
        		glVertex3f(0,2,0);
		    glEnd();	
			glBegin(GL_LINES);
				glColor3f(0,0,0);
				glVertex3f(0,0,0);
		       	glVertex3f(0,0,1);
		      	glVertex3f(0,0,1);
		       	glVertex3f(0,2,1);
		       	glVertex3f(0,2,1);
		       	glVertex3f(0,2,0);
		       	glVertex3f(0,2,0);
		       	glVertex3f(0,0,0);
			glEnd();    
        glPopMatrix();
        // fim janela 2
        
		// JANELA 3
        glPushMatrix();
        	glBegin(GL_QUADS);
        		glColor3f(1,1,1); // Branco
        		glVertex3f(10,6,25);
        		glVertex3f(10,6,26);
        		glVertex3f(10,8,26);
        		glVertex3f(10,8,25);
		    glEnd();
		    glBegin(GL_LINES);
		    	glColor3f(0,0,0);
				glVertex3f(10,6,25);
				glVertex3f(10,6,26);
				glVertex3f(10,6,26);
				glVertex3f(10,8,26);
				glVertex3f(10,8,26);
				glVertex3f(10,8,25);
				glVertex3f(10,8,25);
				glVertex3f(10,6,25);
            glEnd();
        glPopMatrix();
		
        glPushMatrix();
        	glTranslatef(10,6,transJ3); //10,6,24
        	glBegin(GL_QUADS);
        		glColor3f(1,1,1); // Branco
        		glVertex3f(0,0,0);
        		glVertex3f(0,0,1);
        		glVertex3f(0,2,1);
        		glVertex3f(0,2,0);
		    glEnd();	
			glBegin(GL_LINES);
				glColor3f(0,0,0);
				glVertex3f(0,0,0);
		       	glVertex3f(0,0,1);
		      	glVertex3f(0,0,1);
		       	glVertex3f(0,2,1);
		       	glVertex3f(0,2,1);
		       	glVertex3f(0,2,0);
		       	glVertex3f(0,2,0);
		       	glVertex3f(0,0,0);
			glEnd();    
        glPopMatrix(); 		
        // fim janela 3
        
        // JANELA 4
        glPushMatrix();        	
        	glBegin(GL_QUADS);
        		glColor3f(1,1,1); // Branco
        		glVertex3f(10,6,19);
        		glVertex3f(10,6,20);
        		glVertex3f(10,8,20);
        		glVertex3f(10,8,19);
		    glEnd();
			glBegin(GL_LINES);
				glColor3f(0,0,0);
				glVertex3f(10,6,19);
				glVertex3f(10,6,20);
				glVertex3f(10,6,20);
				glVertex3f(10,8,20);
				glVertex3f(10,8,20);
				glVertex3f(10,8,19);
				glVertex3f(10,8,19);
				glVertex3f(10,6,19);
			glEnd();				    
        glPopMatrix();
        
        glPushMatrix();
        	glTranslatef(10,6,transJ4); // 10,6,18
        	glBegin(GL_QUADS);
        		glColor3f(1,1,1); // Branco
        		glVertex3f(0,0,0);
        		glVertex3f(0,0,1);
        		glVertex3f(0,2,1);
        		glVertex3f(0,2,0);
		    glEnd();	
			glBegin(GL_LINES);
				glColor3f(0,0,0);
				glVertex3f(0,0,0);
		       	glVertex3f(0,0,1);
		      	glVertex3f(0,0,1);
		       	glVertex3f(0,2,1);
		       	glVertex3f(0,2,1);
		       	glVertex3f(0,2,0);
		       	glVertex3f(0,2,0);
		       	glVertex3f(0,0,0);
			glEnd();    
        glPopMatrix(); 
        		
		// traços de borda LINHAS
		glPushMatrix();
			glLineWidth(2.0f);
            glColor3f(0, 0, 0); // cinza ardósia
            glBegin(GL_LINES);
            // paredes
	    	glVertex3f(15.1,0.1,15.1);
	    	glVertex3f(15.1,10,15.1);
	    	glVertex3f(10,0.1,30);
	    	glVertex3f(10,10,30);
	    	glVertex3f(15,0.1,30);
	    	glVertex3f(15,10,30);
	    	glVertex3f(10,0.1,10);
	    	glVertex3f(10,10,10);
	    	glVertex3f(20,0.1,10);
	    	glVertex3f(20,10,10);
	    	glVertex3f(20,0.1,15);
	    	glVertex3f(20,10,15);
	    	// telhado
	    	glVertex3f(17,9.5,30.4);
	    	glVertex3f(12.5,12.5,28);
	    	glVertex3f(8,9.5,30.4);
	    	glVertex3f(12.5,12.5,28);
	    	glVertex3f(17,9.5,30.4);
	    	glVertex3f(8,9.5,30.4);
	    	glVertex3f(12.5,12.5,28);
	    	glVertex3f(12.5,12.5,12.5);
	    	glVertex3f(17.5,12.5,12.5);
	    	glVertex3f(12.5,12.5,12.5);
	    	glVertex3f(20.5,9.5,8);
	    	glVertex3f(17.5,12.5,12.5);
	    	glVertex3f(17.5,12.5,12.5);
	    	glVertex3f(20.5,9.5,17);
	    	glVertex3f(20.5,9.5,17);
	    	glVertex3f(20.5,9.5,8);
	    	glVertex3f(17,9.5,30.4);
	    	glVertex3f(17,9.5,17);
	    	glVertex3f(17,9.5,17);
	    	glVertex3f(20.5,9.5,17);
	    	glVertex3f(17.1,9.6,17.1);
	    	glVertex3f(12.6,12.6,12.6);
			glVertex3f(8,9.5,8);
			glVertex3f(8,9.5,30.4);
			glVertex3f(8,9.5,8);
  	 		glVertex3f(12.5,12.5,12.5);
  	 		glVertex3f(8,9.5,8);
  	 		glVertex3f(20.5,9.5,8);	    	
			glEnd(); 
	    glPopMatrix();	    
	    
  	 	// FIM CASA        
	    glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 20.0, 20.0, 1.0};
	
	quadratic = gluNewQuadric(); // cilindro 

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	 
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

    //angle=45;
    ANGULO = 45;
    rotX = rotY = 0;
    obsX = obsY = 0;
    obsZ = 60;//Voltar para 10 -- define posição da geração da tela, o ponto C
    escalaX = escalaY = escalaZ = 1;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void) //equivalente ao posiciona observador
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    //gluPerspective(angle,fAspect,0.4,500);
    gluPerspective(ANGULO, ASPECTO, 0.4, 500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
    //gluLookAt(0,80,200, 0,0,0, 0,1,0);
    //gluLookAt(obsX, obsY, obsZ, 0,0,0, 0,1,0);
    glTranslatef(-obsX, -obsY, -obsZ);/*Translata a cÃ¢mera para essas variÃ¡veis*/
    glRotatef(rotX,1,0,0);/*Rotacionar a cÃ¢mera para essas coordenadas*/
    glRotatef(rotY,0,1,0); 
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	//fAspect = (GLfloat)w/(GLfloat)h;
	ASPECTO = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	/*if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}*/
	if(state == GLUT_DOWN){
		x_ini = x;
        y_ini = y;
        obsX_ini = obsX;
        obsY_ini = obsY;
        obsZ_ini = obsZ;
        rotX_ini = rotX;
        rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

        void motion(int x, int y){
            if(bot == GLUT_LEFT_BUTTON){//RotaÃ§Ã£o
                int deltaX = x_ini - x;
                int deltaY = y_ini - y; 
                rotX = rotX_ini - deltaY/ SENS_ROT;
                rotY = rotY_ini - deltaX/ SENS_ROT;
             }
             else if (bot == GLUT_RIGHT_BUTTON){//Zoom
                 int deltaZ = y_ini - y;
                 obsZ = obsZ_ini + deltaZ/ SENS_OBS;
             }
             else if (bot == GLUT_MIDDLE_BUTTON){//Correr
                 int deltaX = x_ini - x;
                 int deltaY = y_ini - y;
                 obsX = obsX_ini + deltaX/ SENS_TRANS;
                 obsY = obsY_ini + deltaY/ SENS_TRANS;
             }
             EspecificaParametrosVisualizacao();
             glutPostRedisplay();
        }

// Programa Principal
int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutCreateWindow("CASA 'L' ");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutMotionFunc(motion);
	glutIdleFunc(idle);					// date class 05-11-18
    glutKeyboardFunc(key);				// funcao teclado.
	Inicializa();
	glutMainLoop();
}

