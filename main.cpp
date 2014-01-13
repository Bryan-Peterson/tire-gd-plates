#include "include.h"

bool load_file;
bool updateDraw;
bool showSphere;
bool movewall;
bool savenow; 

ANCFSystem sys;

//RENDERING STUFF
float m_MaxPitchRate;
float m_MaxHeadingRate;
float3 camera_pos;
float3 look_at;
float3 camera_up;
float camera_heading, camera_pitch;
float3 dir;
float2 mouse_pos;
float3 camera_pos_delta;

void initializeCamera()
{
	load_file=false;
	updateDraw=true;
	showSphere=true;
	movewall=true;
	savenow=false;

	//RENDERING STUFF
	m_MaxPitchRate=5;
	m_MaxHeadingRate=5;
	camera_pos=make_float3(0,0,5);
	look_at=make_float3(0,0,0);
	//camera_pos=make_float3(-1,0,0);
	//look_at=make_float3(0,0,0);
	camera_up=make_float3(0,1,0);
	camera_heading=0; 
	camera_pitch=0;

	//dir=make_float3(1,0,0);
	dir=make_float3(0,0,-1);
	mouse_pos=make_float2(0,0);
	camera_pos_delta=make_float3(0,0,0);
}

float4 CreateFromAxisAngle(float3 axis, float degrees){
	float angle = float((degrees / 180.0f) * PI);
	float result = (float)sin( angle / 2.0f );
	float4 camera_quat;
	camera_quat.w = (float)cos( angle / 2.0f );
	camera_quat.x = float(axis.x * result);
	camera_quat.y = float(axis.y * result);
	camera_quat.z = float(axis.z * result);
	return camera_quat;
}

inline float4 squig(const float4& a){
	return (1.0/(dot(a,a)))*(make_float4(-1*make_float3(a),a.w));
}
inline float4 mult(const float4 &a, const float4 &b){
	return make_float4(a.w*make_float3(b)+b.w*make_float3(a)+cross(make_float3(a),make_float3(b)),a.w*b.w-dot(make_float3(a),make_float3(b)));
}
inline float3 quatRotate(const float3 &v, const float4 &q){
	return make_float3(mult(mult(q,make_float4(v,0)),squig(q)));
}

void ChangePitch(GLfloat degrees)
{
	if(fabs(degrees) < fabs(m_MaxPitchRate)){
		camera_pitch += degrees;
	}else{
		if(degrees < 0){
			camera_pitch -= m_MaxPitchRate;
		}else{
			camera_pitch += m_MaxPitchRate;
		}
	}
	if(camera_pitch > 360.0f){
		camera_pitch -= 360.0f;
	}else if(camera_pitch < -360.0f){
		camera_pitch += 360.0f;
	}
}

void ChangeHeading(GLfloat degrees){
	if(fabs(degrees) < fabs(m_MaxHeadingRate)){
		if(camera_pitch > 90 && camera_pitch < 270 || (camera_pitch < -90 && camera_pitch > -270)){
			camera_heading -= degrees;
		}
		else{
			camera_heading += degrees;
		}
	}
	else{
		if(degrees < 0){
			if((camera_pitch > 90 && camera_pitch < 270) || (camera_pitch < -90 && camera_pitch > -270)){
				camera_heading += m_MaxHeadingRate;
			}else{
				camera_heading -= m_MaxHeadingRate;
			}
		}else{
			if(camera_pitch > 90 && camera_pitch < 270 || (camera_pitch < -90 && camera_pitch > -270)){
				camera_heading -= m_MaxHeadingRate;
			}else{
				camera_heading += m_MaxHeadingRate;
			}
		}
	}
	if(camera_heading > 360.0f){
		camera_heading -= 360.0f;
	}else if(camera_heading < -360.0f){
		camera_heading += 360.0f;
	}
}

void processNormalKeys(unsigned char key, int x, int y) { 	
	if (key=='w'){camera_pos_delta+=dir*.05*SCALE;}
	if (key=='s'){camera_pos_delta-=dir*.05*SCALE;}
	if (key=='d'){camera_pos_delta+=cross(dir,camera_up)*.05*SCALE;}
	if (key=='a'){camera_pos_delta-=cross(dir,camera_up)*.05*SCALE;}
	if (key=='q'){camera_pos_delta+=camera_up*.05*SCALE;}
	if (key=='e'){camera_pos_delta-=camera_up*.05*SCALE;}
	if (key=='u'){updateDraw=(updateDraw)? 0:1;}
	if (key=='i'){showSphere=(showSphere)? 0:1;}
	if (key=='z'){savenow=1;}
	if (key=='x'){movewall=1;}
}

void pressKey(int key, int x, int y) {} 
void releaseKey(int key, int x, int y) {}

void mouseMove(int x, int y) { 
	float2 mouse_delta=mouse_pos-make_float2(x,y);
	ChangeHeading(.2 * mouse_delta.x);
	ChangePitch(.2 * mouse_delta.y);
	mouse_pos=make_float2(x,y);
}

void mouseButton(int button, int state, int x, int y) {
	mouse_pos=make_float2(x,y);
}

void changeSize(int w, int h) {
	if(h == 0) {h = 1;}
	float ratio = 1.0* w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,.1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,0.0,		0.0,0.0,-7,		0.0f,1.0f,0.0f);
}

void initScene(){
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };			
	glClearColor (1.0, 1.0, 1.0, 0.0);							
	glShadeModel (GL_SMOOTH);									
	glEnable(GL_COLOR_MATERIAL);								
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);			
	glEnable(GL_LIGHTING);										
	glEnable(GL_LIGHT0);
	glEnable (GL_POINT_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint (GL_POINT_SMOOTH_HINT, GL_DONT_CARE);
}

void drawAll()
{
	if(updateDraw){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glFrontFace(GL_CCW);
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
		glDepthFunc(GL_LEQUAL);
		glClearDepth(1.0);

		glPointSize(2);
		glLoadIdentity();

		float4 pitch_quat=CreateFromAxisAngle(cross(dir,camera_up), camera_pitch);
		float4 heading_quat=CreateFromAxisAngle(camera_up, camera_heading);

		dir=quatRotate(dir,normalize(mult(pitch_quat,heading_quat)));
		camera_pos+=camera_pos_delta;
		look_at=camera_pos+dir*1;

		camera_heading*=.5;
		camera_pitch*=.5;
		camera_pos_delta*=.5;

		gluLookAt(	
			camera_pos.x, camera_pos.y, camera_pos.z,
			look_at.x, look_at.y,  look_at.z,
			camera_up.x, camera_up.y,  camera_up.z);
		
//		glColor3f(1.0f,0.0f,0.0f);
//		glPushMatrix();
//		glTranslatef(sys.sphere.x,sys.sphere.y,sys.sphere.z);
//		glutSolidSphere(sys.sphere.w,100,100);
//		glPopMatrix();

		glColor3f(0.0f,1.0f,0.0f);
		glBegin(GL_QUADS);
		double clip =1;
		glVertex3f(clip,sys.groundHeight,clip);
		glVertex3f(clip,sys.groundHeight,-clip);
		glVertex3f(-clip,sys.groundHeight,-clip);
		glVertex3f(-clip,sys.groundHeight,clip);
		glEnd();
		glFlush();
		//sys.DoTimeStep();
		for(int i=0;i<sys.elements.size();i++)
		{
			int xiDiv = sys.numContactPoints.x;
			int etaDiv = sys.numContactPoints.y;

			double xiInc = 1/((double)(xiDiv-1));
			double etaInc = 1/((double)(etaDiv-1));
			int square=0;

			if(showSphere)
			{
				glColor3f(0.0f,0.0f,1.0f);
				for(int j=0;j<xiDiv;j++)
				{
					for(int k=0;k<etaDiv;k++)
					{
						glPushMatrix();
						float3 position = sys.getXYZPosition(i,xiInc*j,etaInc*k);
						glTranslatef(position.x,position.y,position.z);
						glutSolidSphere(sys.elements[i].getThickness()*.5,10,10);
						glPopMatrix();
					}
				}
			}
			else
			{
				glLineWidth(sys.elements[i].getThickness()*500);
				glColor3f(0.0f,0.0f,1.0f);
				glBegin(GL_QUADS);
				for(int j=0;j<xiDiv-1;j++)
				{
					for(int k=0;k<etaDiv-1;k++)
					{
						glColor3f(0.0f,1.0f,0.0f);
						if(square%2==0) glColor3f(0.0f,0.0f,1.0f);
						float3 position = sys.getXYZPosition(i,xiInc*j,etaInc*k);
						glVertex3f(position.x,position.y,position.z);
						position = sys.getXYZPosition(i,xiInc*(j+1),etaInc*k);
						glVertex3f(position.x,position.y,position.z);
						position = sys.getXYZPosition(i,xiInc*(j+1),etaInc*(k+1));
						glVertex3f(position.x,position.y,position.z);
						position = sys.getXYZPosition(i,xiInc*j,etaInc*(k+1));
						glVertex3f(position.x,position.y,position.z);

						position = sys.getXYZPosition(i,xiInc*j,etaInc*k);
						glVertex3f(position.x,position.y,position.z);
						position = sys.getXYZPosition(i,xiInc*j,etaInc*(k+1));
						glVertex3f(position.x,position.y,position.z);
						position = sys.getXYZPosition(i,xiInc*(j+1),etaInc*(k+1));
						glVertex3f(position.x,position.y,position.z);
						position = sys.getXYZPosition(i,xiInc*(j+1),etaInc*k);
						glVertex3f(position.x,position.y,position.z);

						square++;
					}
				}
				glEnd();
				glFlush();
			}
		}

		glutSwapBuffers();
	} 
}

void renderSceneAll(){
	if(OGL){drawAll();}
}

int main(int argc, char** argv)
{
	sys.setTimeStep(1e-3);
	sys.setTolerance(1e-3);

	//TIRE 2
	int numDiv = atoi(argv[1]);
	double radianInc = 2.0*PI/((double) numDiv);

	double EM = 2.e8;
	double rho = 7810.0;
	double th = .01;
	double R = .2;
	double fillet = .04;
	double beltWidth = .1;
	double B = .5*PI*beltWidth;
	double L = 2*PI*R/((double) numDiv);
	sys.numContactPoints = make_int2(15,20);
	sys.groundHeight = -R-beltWidth-th;
	vector<Node> nodes;
	for(int i=0;i<numDiv;i++)
	{
		nodes.push_back(Node(R*cos(radianInc*i),R*sin(radianInc*i),0,-sin(radianInc*i),cos(radianInc*i),0,cos(radianInc*i),sin(radianInc*i),0));
		nodes.push_back(Node(R*cos(radianInc*i),R*sin(radianInc*i),beltWidth,-sin(radianInc*i),cos(radianInc*i),0,-cos(radianInc*i),-sin(radianInc*i),0));
	}

	Element element;
	for(int i=0;i<numDiv-1;i++)
	{
		element = Element(nodes[2*i],nodes[2*i+2],nodes[2*i+3],nodes[2*i+1]);
		element.setThickness(th);
		element.setLength_l(L);
		element.setLength_b(B);
		element.setElasticModulus(EM);
		element.setDensity(rho);
		sys.addElement(element);
	}

	element = Element(nodes[2*(numDiv-1)],nodes[0],nodes[1],nodes[2*(numDiv-1)+1]);
	element.setThickness(th);
	element.setLength_l(L);
	element.setLength_b(B);
	element.setElasticModulus(EM);
	element.setDensity(rho);
	sys.addElement(element);

	for(int i=0;i<numDiv-1;i++)
	{
		sys.addConstraint_RelativeFixed(sys.elements[i],1,sys.elements[i+1],0);
		sys.addConstraint_RelativeFixed(sys.elements[i],2,sys.elements[i+1],3);
	}

	sys.addConstraint_RelativeFixed(sys.elements[numDiv-1],1,sys.elements[0],0);
	sys.addConstraint_RelativeFixed(sys.elements[numDiv-1],2,sys.elements[0],3);

	sys.addConstraint_AbsoluteX(sys.elements[0],1);
	sys.addConstraint_AbsoluteZ(sys.elements[0],1);

	sys.addConstraint_AbsoluteX(sys.elements[0],2);
	sys.addConstraint_AbsoluteZ(sys.elements[0],2);

	//sys.addConstraint_AbsoluteSpherical(0);
	//for(int i=0;i<sys.elements.size()*4;i++) sys.addConstraint_AbsoluteFixed(i);

//	sys.addConstraint_RelativeFixed(element0,0,element3,1);
//	sys.addConstraint_RelativeFixed(element0,3,element3,2);
//	sys.addConstraint_RelativeFixed(element0,1,element1,0);
//	sys.addConstraint_RelativeFixed(element0,2,element1,3);
//	sys.addConstraint_RelativeFixed(element1,1,element2,0);
//	sys.addConstraint_RelativeFixed(element1,2,element2,3);
//	sys.addConstraint_RelativeFixed(element2,1,element3,0);
//	sys.addConstraint_RelativeFixed(element2,2,element3,3);

//	//TIRE 2
//	double EM = 2.e8;
//	double EM2 = 2.e6;
//	double rho = 7801.0;
//	double th = .01;
//	double R = .2;
//	double fillet = .04;
//	double beltWidth = .1;
//	double B = .5*PI*fillet;
//	double L = .5*PI*R;
//	sys.numContactPoints = make_int2(10,5);
//	sys.groundHeight = -R-th;
//	vector<Node> nodes;
//	Node node = Node(R,0,0,0,1,0,0,0,1);
//	nodes.push_back(node);
//	node = Node(R,0,beltWidth,0,1,0,0,0,1);
//	nodes.push_back(node);
//	node = Node(0,R,0,-1,0,0,0,0,1);
//	nodes.push_back(node);
//	node = Node(0,R,beltWidth,-1,0,0,0,0,1);
//	nodes.push_back(node);
//	node = Node(-R,0,0,0,-1,0,0,0,1);
//	nodes.push_back(node);
//	node = Node(-R,0,beltWidth,0,-1,0,0,0,1);
//	nodes.push_back(node);
//	node = Node(0,-R,0,1,0,0,0,0,1);
//	nodes.push_back(node);
//	node = Node(0,-R,beltWidth,1,0,0,0,0,1);
//	nodes.push_back(node);
//
//	// nodes for sidewall
//	node = Node(R-fillet,0,-fillet,0,1,0,1,0,0);
//	nodes.push_back(node);
//
//	node = Node(R-fillet,0,beltWidth+fillet,0,1,0,-1,0,0);
//	nodes.push_back(node);
//
//	node = Node(0,R-fillet,-fillet,-1,0,0,0,1,0);
//	nodes.push_back(node);
//
//	node = Node(0,R-fillet,beltWidth+fillet,-1,0,0,0,-1,0);
//	nodes.push_back(node);
//
//	node = Node(-R+fillet,0,-fillet,0,-1,0,1,0,0);
//	nodes.push_back(node);
//
//	node = Node(-R+fillet,0,beltWidth+fillet,0,-1,0,-1,0,0);
//	nodes.push_back(node);
//
//	node = Node(0,fillet-R,-fillet,1,0,0,0,-1,0);
//	nodes.push_back(node);
//
//	node = Node(0,fillet-R,beltWidth+fillet,1,0,0,0,1,0);
//	nodes.push_back(node);
//
//	Element element0 = Element(nodes[0],nodes[2],nodes[3],nodes[1]);
//	element0.setThickness(th);
//	element0.setLength_l(L);
//	element0.setElasticModulus(EM);
//	element0.setDensity(rho);
//	sys.addElement(element0);
//
//	Element element1 = Element(nodes[2],nodes[4],nodes[5],nodes[3]);
//	element1.setThickness(th);
//	element1.setLength_l(L);
//	element1.setElasticModulus(EM);
//	element1.setDensity(rho);
//	sys.addElement(element1);
//
//	Element element2 = Element(nodes[4],nodes[6],nodes[7],nodes[5]);
//	element2.setThickness(th);
//	element2.setLength_l(L);
//	element2.setElasticModulus(EM);
//	element2.setDensity(rho);
//	sys.addElement(element2);
//
//	Element element3 = Element(nodes[6],nodes[0],nodes[1],nodes[7]);
//	element3.setThickness(th);
//	element3.setLength_l(L);
//	element3.setElasticModulus(EM);
//	element3.setDensity(rho);
//	sys.addElement(element3);
//
//	Element element4 = Element(nodes[8],nodes[10],nodes[2],nodes[0]);
//	element4.setThickness(th);
//	element4.setLength_l(L);
//	element4.setLength_b(B);
//	element4.setElasticModulus(EM2);
//	element4.setDensity(rho);
//	sys.addElement(element4);
//
//	Element element5 = Element(nodes[1],nodes[3],nodes[11],nodes[9]);
//	element5.setThickness(th);
//	element5.setLength_l(L);
//	element5.setLength_b(B);
//	element5.setElasticModulus(EM2);
//	element5.setDensity(rho);
//	sys.addElement(element5);
//
//	Element element6 = Element(nodes[10],nodes[12],nodes[4],nodes[2]);
//	element6.setThickness(th);
//	element6.setLength_l(L);
//	element6.setLength_b(B);
//	element6.setElasticModulus(EM2);
//	element6.setDensity(rho);
//	sys.addElement(element6);
//
//	Element element7 = Element(nodes[3],nodes[5],nodes[13],nodes[11]);
//	element7.setThickness(th);
//	element7.setLength_l(L);
//	element7.setLength_b(B);
//	element7.setElasticModulus(EM2);
//	element7.setDensity(rho);
//	sys.addElement(element7);
//
//	Element element8 = Element(nodes[12],nodes[14],nodes[6],nodes[4]);
//	element8.setThickness(th);
//	element8.setLength_l(L);
//	element8.setLength_b(B);
//	element8.setElasticModulus(EM2);
//	element8.setDensity(rho);
//	sys.addElement(element8);
//
//	Element element9 = Element(nodes[5],nodes[7],nodes[15],nodes[13]);
//	element9.setThickness(th);
//	element9.setLength_l(L);
//	element9.setLength_b(B);
//	element9.setElasticModulus(EM2);
//	element9.setDensity(rho);
//	sys.addElement(element9);
//
//	Element element10 = Element(nodes[14],nodes[8],nodes[0],nodes[6]);
//	element10.setThickness(th);
//	element10.setLength_l(L);
//	element10.setLength_b(B);
//	element10.setElasticModulus(EM2);
//	element10.setDensity(rho);
//	sys.addElement(element10);
//
//	Element element11 = Element(nodes[7],nodes[1],nodes[9],nodes[15]);
//	element11.setThickness(th);
//	element11.setLength_l(L);
//	element11.setLength_b(B);
//	element11.setElasticModulus(EM2);
//	element11.setDensity(rho);
//	sys.addElement(element11);
//
//	//for(int i=0;i<sys.elements.size()*4;i++) sys.addConstraint_AbsoluteFixed(i);
//
//	sys.addConstraint_RelativeFixed(element0,0,element3,1);
//	sys.addConstraint_RelativeFixed(element0,3,element3,2);
//	sys.addConstraint_RelativeFixed(element0,1,element1,0);
//	sys.addConstraint_RelativeFixed(element0,2,element1,3);
//	sys.addConstraint_RelativeFixed(element1,1,element2,0);
//	sys.addConstraint_RelativeFixed(element1,2,element2,3);
//	sys.addConstraint_RelativeFixed(element2,1,element3,0);
//	sys.addConstraint_RelativeFixed(element2,2,element3,3);
//
//	sys.addConstraint_RelativeFixed(element0,0,element4,3);
//	sys.addConstraint_RelativeFixed(element0,1,element4,2);
//	sys.addConstraint_RelativeFixed(element0,3,element5,0);
//	sys.addConstraint_RelativeFixed(element0,2,element5,1);
//
//	sys.addConstraint_RelativeFixed(element1,0,element6,3);
//	sys.addConstraint_RelativeFixed(element1,1,element6,2);
//	sys.addConstraint_RelativeFixed(element1,3,element7,0);
//	sys.addConstraint_RelativeFixed(element1,2,element7,1);
//
//	sys.addConstraint_RelativeFixed(element2,0,element8,3);
//	sys.addConstraint_RelativeFixed(element2,1,element8,2);
//	sys.addConstraint_RelativeFixed(element2,3,element9,0);
//	sys.addConstraint_RelativeFixed(element2,2,element9,1);
//
//	sys.addConstraint_RelativeFixed(element3,0,element10,3);
//	sys.addConstraint_RelativeFixed(element3,1,element10,2);
//	sys.addConstraint_RelativeFixed(element3,3,element11,0);
//	sys.addConstraint_RelativeFixed(element3,2,element11,1);
//
//	sys.addConstraint_RelativeFixed(element4,1,element6,0);
//	sys.addConstraint_RelativeFixed(element6,1,element8,0);
//	sys.addConstraint_RelativeFixed(element8,1,element10,0);
//	sys.addConstraint_RelativeFixed(element10,1,element4,0);
//
//	sys.addConstraint_RelativeFixed(element5,2,element7,3);
//	sys.addConstraint_RelativeFixed(element7,2,element9,3);
//	sys.addConstraint_RelativeFixed(element9,2,element11,3);
//	sys.addConstraint_RelativeFixed(element11,2,element5,3);
//  // END TIRE 2

	printf("Initializing system... ");
	sys.initializeSystem();
	printf("System Initialized!\n");

//	while(sys.getCurrentTime()<=10)
//	{
//
//		sys.DoTimeStep();
//	}

	while(sys.getCurrentTime()<=5)
	{
		if(sys.getTimeIndex()%10==0) sys.writeToFile();
		sys.DoTimeStep();
	}
	printf("Total time: %f [s]\n",sys.timeToSimulate);

//#pragma omp parallel sections
//	{
//#pragma omp section
//		{
//			while(true)
//			{
//				sys.DoTimeStep();
//			}
//		}
//#pragma omp section
//		{
//			if(OGL){
//				initializeCamera();
//				glutInit(&argc, argv);
//				glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//				glutInitWindowPosition(0,0);
//				glutInitWindowSize(1024	,512);
//				glutCreateWindow("MAIN");
//				glutDisplayFunc(renderSceneAll);
//				glutIdleFunc(renderSceneAll);
//				glutReshapeFunc(changeSize);
//				glutIgnoreKeyRepeat(0);
//				glutKeyboardFunc(processNormalKeys);
//				glutMouseFunc(mouseButton);
//				glutMotionFunc(mouseMove);
//				initScene();
//				glutMainLoop();
//			}
//		}
//	}

	return 0;
}
