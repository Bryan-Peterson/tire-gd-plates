#include "include.h"

bool WaveFrontReader::isUnique(int2 edge)
{
	for(int i=0;i<edges.size();i++)
	{
		if(edge.x==edges[i].x&&edge.y==edges[i].y) return false;
	}
	return true;
}

int WaveFrontReader::readOBJ(string fileName)
{
	char id;
	string line;
	ifstream myfile (fileName.c_str());
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
			getline (myfile,line);
			switch(line[0])
			{
			case 'v':
				if(line[1]!='n')
				{
					char type;
					float v1;
					float v2;
					float v3;
					std::stringstream ss(line);
					ss>>type>>v1>>v2>>v3;
					vertices.push_back(make_float3(v1,v2,v3));
					//cout << type << " " << v1 << " " << v2 << " " << v3 << endl;
				}
				break;
			case 'f':
				/*
				char type;
				float v1;
				float v2;
				float v3;
				std::stringstream ss(line);
				ss>>type>>v1>>v2>>v3;
				faces.push_back(make_int3(v1,v2,v3));
				*/

				char type;
				string s1;
				string s2;
				string s3;
				std::stringstream ss(line);
				ss>>type>>s1>>s2>>s3;
				int f1 = atoi(s1.substr(0,s1.find_first_of("/")).c_str());
				int f2 = atoi(s2.substr(0,s2.find_first_of("/")).c_str());
				int f3 = atoi(s3.substr(0,s3.find_first_of("/")).c_str());
				faces.push_back(make_int3(f1,f2,f3));
				//cout << type << " " << f1 << " " << f2 << " " << f3 << endl;



			}
		}
		myfile.close();
	}

	else cout << "Unable to open file"; 

	// add unique edges to vector
	for(int i=0;i<faces.size();i++)
	{
		int3 face = faces[i];

		int2 edge = make_int2(min(face.x,face.y),max(face.x,face.y));
		if(isUnique(edge)) edges.push_back(edge);

		edge = make_int2(min(face.y,face.z),max(face.y,face.z));
		if(isUnique(edge)) edges.push_back(edge);

		edge = make_int2(min(face.z,face.x),max(face.z,face.x));
		if(isUnique(edge)) edges.push_back(edge);
	}

//	//cout << "Edges: " << endl;
//	for(int i=0;i<edges.size();i++)
//		cout << i << " " << edges[i].x << " " << edges[i].y << endl;
//	cin.get();

	return 0;
}
