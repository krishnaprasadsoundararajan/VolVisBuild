#include<FeatureVector.h>
#include <vtkImageData.h>
#include <vtkXMLImageDataReader.h>
#include <fstream>


#define PTR vtkSmartPointer
FeatureVector::FeatureVector()
{
	ofstream outputFile;
    outputFile.open("E:/Semester III/Thesis/program3data.txt");
	cout<<"File created";
	PTR<vtkXMLImageDataReader> source = PTR<vtkXMLImageDataReader>::New();
	source->SetFileName("I:/assignment-06-octree-solution (1)/assignment-06-octree-solution/headsq-half.vti");
	source->Update();
	PTR<vtkImageData> colorImage = source->GetOutput();
	colorImage->UpdateInformation();
	int extent[6];
	double *g = new double[3];
  extent[0] = extent[1] = extent[2] = extent[3] = extent[4] = extent[5] = 0; 
  colorImage->GetExtent(extent);
	for(int x = extent[0]; x < extent[1]; x++) //extent[1]
	   for(int y = extent[2]; y < extent[3]; y++)//extent[3]
		  for(int z = extent[4]; z < extent[5]; z++)//extent[5]
		   {
			   GetPointGradient(x,y,z,colorImage,g);
			   if(g[0]!=0 && g[1]!=0 && g[2]!=0)
			   outputFile<<(x+y*(extent[1] - extent[0])+z*(extent[1] - extent[0])*(extent[3] - extent[2]))<<" : "<<"1:"<<g[0]<<" 2:"<<g[1]<<" 3:" <<g[2]<<endl;
			  // cout<<"GRADIENT"<<g[0]<<" " <<g[1]<<" "<<g[2]<<endl;
		   }
		  outputFile.close();
}
void FeatureVector::GetPointGradient(int i, int j, int k, vtkImageData *s,double *g)
{
  //double g[3];
  double *ar;
 // cout<<" I: :"<<i<<" j: :"<<j<<" k: :"<<k<<endl;
  //s->GetSpacing(ar);
  double sp, sm;
  int extent[6];
  extent[0] = extent[1] = extent[2] = extent[3] = extent[4] = extent[5] = 0; 
  s->GetExtent(extent);
  vtkIdType dims[3];
  dims[0] = extent[1] - extent[0] + 1;
  dims[1] = extent[3] - extent[2] + 1;
  dims[2] = extent[5] - extent[4] + 1;
  ar=s->GetSpacing();
  //vtkIdType ijsize=dims[0]*dims[1];

  // Adjust i,j,k to the start of the extent
  //i -= extent[0];
  //j -= extent[2];
  //k -= extent[4];
 // cout<<"After I: :"<<i<<" j: :"<<j<<" k: :"<<k<<endl;
  // Check for out-of-bounds
  if (i < extent[0] || i >= dims[0] || j < extent[2] || j >= dims[1] || k < extent[4] || k >= dims[2])
    {
    g[0] = g[1] = g[2] = 0.0;
    return;
    }

  // x-direction
  if ( dims[0] == 1 )
    {
    g[0] = 0.0;
    }
  else if ( i == extent[0]  )
    {
		sp = s->GetScalarComponentAsFloat(i+1,j,k,0);
		sm = s->GetScalarComponentAsFloat(i,j,k,0);
        g[0] = (sm - sp) / ar[0];
    }
  else if ( i == (dims[0]-1) )
    {
		sp = s->GetScalarComponentAsDouble(i,j,k,0);
		sm = s->GetScalarComponentAsDouble(i-1,j,k,0);
    //sp = s->GetComponent(i + j*dims[0] + k*ijsize,0);
    //sm = s->GetComponent(i-1 + j*dims[0] + k*ijsize,0);
        g[0] = (sm - sp) / ar[0];
    }
  else
    {
		sp = s->GetScalarComponentAsDouble(i+1,j,k,0);
		sm = s->GetScalarComponentAsDouble(i-1,j,k,0);
    //sp = s->GetComponent(i+1 + j*dims[0] + k*ijsize,0);
    //sm = s->GetComponent(i-1 + j*dims[0] + k*ijsize,0);
    g[0] = 0.5 * (sm - sp) / ar[0];
    }

  // y-direction
  if ( dims[1] == 1 )
    {
    g[1] = 0.0;
    }
  else if ( j == extent[2] )
    {
		sp = s->GetScalarComponentAsDouble(i,j+1,k,0);
		sm = s->GetScalarComponentAsDouble(i,j,k,0);
    //sp = s->GetComponent(i + (j+1)*dims[0] + k*ijsize,0);
    //sm = s->GetComponent(i + j*dims[0] + k*ijsize,0);
    g[1] = (sm - sp) / ar[1];
    }
  else if ( j == (dims[1]-1) )
    {
		sp = s->GetScalarComponentAsDouble(i,j,k,0);
		sm = s->GetScalarComponentAsDouble(i,j-1,k,0);
    //sp = s->GetComponent(i + j*dims[0] + k*ijsize,0);
    //sm = s->GetComponent(i + (j-1)*dims[0] + k*ijsize,0);
    g[1] = (sm - sp) / ar[1];
    }
  else
    {
		sp = s->GetScalarComponentAsDouble(i,j+1,k,0);
		sm = s->GetScalarComponentAsDouble(i,j-1,k,0);
    //sp = s->GetComponent(i + (j+1)*dims[0] + k*ijsize,0);
    //sm = s->GetComponent(i + (j-1)*dims[0] + k*ijsize,0);
    g[1] = 0.5 * (sm - sp) / ar[1];
    }

  // z-direction
  if ( dims[2] == 1 )
    {
    g[2] = 0.0;
    }
  else if ( k == extent[4] )
    {
		sp = s->GetScalarComponentAsDouble(i,j,k+1,0);
		sm = s->GetScalarComponentAsDouble(i,j,k,0);
    //sp = s->GetComponent(i + j*dims[0] + (k+1)*ijsize,0);
    //sm = s->GetComponent(i + j*dims[0] + k*ijsize,0);
    g[2] = (sm - sp) / ar[2];
    }
  else if ( k == (dims[2]-1) )
    {
		sp = s->GetScalarComponentAsDouble(i,j,k,0);
		sm = s->GetScalarComponentAsDouble(i,j,k-1,0);
    //sp = s->GetComponent(i + j*dims[0] + k*ijsize,0);
    //sm = s->GetComponent(i + j*dims[0] + (k-1)*ijsize,0);
    g[2] = (sm - sp) / ar[2];
    }
  else
    {
		sp = s->GetScalarComponentAsDouble(i,j,k+1,0);
		sm = s->GetScalarComponentAsDouble(i,j,k-1,0);
    //sp = s->GetComponent(i + j*dims[0] + (k+1)*ijsize,0);
    //sm = s->GetComponent(i + j*dims[0] + (k-1)*ijsize,0);
    g[2] = 0.5 * (sm - sp) / ar[2];
    }
  return;
 // if((g[0]!=0) && (g[1]!=0) && (g[2]!=0))
  //cout<<"GRADIEMT : "<< "I : "<<i<<"j : "<<j<<"k : "<<k<< " "<< g[0] << " " <<g[1] << " "<< g[2]<<endl;
  
}