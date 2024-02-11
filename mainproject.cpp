/*

Assignment 1 (full)

program      : gary scale c++ filter maker
participants : Abdelrhaman Mohsen Faried  --  Omar Mohammed Ahmed -- Ziyad Mohammed Abdullah
ID           :       20221093             --      20220231        --      20221067
course       : CS213 : Object Oriented Programming (Programming 2)
Instructor   : Dr.Mohammad El-Ramly
Date         : 18/9/2023
---------

description : Assignment 1 (all filters) .This submission will include the following filters : 1.Turning a gray scale image into
            a black and white version 2.Inverting a gray scale image (changing every pixel to its opposite colour) 3.Merging 2 images
            4.Filiping an image (horizontaly or verticaly) 5.Rotating an image (90 , 180 , 270 degree) 6.Lightening and darkening images
            7.Detecting image's edges 8.Enlarging image parts 9.Shrinking an image 10.mirroring an image 11.Shuffling image's parts
            12.Bluring an image 13.croping an image 14.skew horizontally 15.sekew vertically.
            We used a small library (bmplimp.bmb and bmplib.h) for loading the pixels of the images in a 2D or 3D array. We used some
            Object Oriented features.
--------
For any comments : 
                Abdulrhman's email -> abdo.mohsen3457643@gmail.com
                Omar's email       -> omarsokar200f4@gmail.com
                Ziyad's email      -> mziyad154@gmail.com

*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
char chose;
void chosing();
bool check_number(char c);
char options[]={'1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
int main();

//-------------------------------------------- turning into Black and White

class filter_BW
{
    private:
        unsigned char image[SIZE][SIZE];                  // the image used by the user with size of 256x265
        char imageFileName[100];
    public:
        void loadImage()                                  // loading the image by the user
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");                // adding .bmb extention for the image file used by the user
            if(readGSBMP(imageFileName, image)==1)main();  // reading the image file entered
        }
        void saveimage()                                 // saving the filtered image
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            writeGSBMP(imageFileName, image);             //writing changes on the filtered image
        }
        void doSomethingForImageBW()                      // turning the image int black and white version by moving the pixel 
        {                                                // to its closest black(0) or white(255) colour 
            for (int i = 0; i < SIZE; i++) 
            {
                for (int j = 0; j< SIZE; j++) 
                {
                    if (image[i][j] > 127)
                        image[i][j] = 255;
                else
                        image[i][j] = 0;
                }
            }
        }
};

//------------------------------------------------ inverting image

class filter_inv 
{
    private:
        unsigned char image[SIZE][SIZE];
        char imageFileName[100];
    public:
        void loadImage()
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            if(readGSBMP(imageFileName, image)==1)main();
            
        }
        void saveimage()
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            writeGSBMP(imageFileName, image);
        }
        void doSomethingForImageinv()                        // inverting the image by the subtracting the pixel form the 
        {                                                    // largest pixel value there (255) giving us the opposite of the colour
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++) 
            {
                image[i][j]=255-image[i][j];
            }
        }
    }
};

//----------------------------------------------- merging image

class filter_merg
{
    private:
        unsigned char image[SIZE][SIZE];
        char imageFileName[100];
        char imageFileName2[100];
        unsigned char image3[SIZE][SIZE];
        unsigned char image2[SIZE][SIZE];
        char imageFileNamenew[100];
    public:
        void load_Image()
        {
            cout << "Enter the source image file name 1: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            if(readGSBMP(imageFileName, image)==1)main();
            cout << "Enter the source image file name 2: ";
            cin >> imageFileName2;
            strcat (imageFileName2, ".bmp");
            if(readGSBMP(imageFileName2, image2)==1)main();
        }
        void save_image()
        {
            cout << "Enter the target image file name: ";
            cin>>imageFileNamenew;
            strcat (imageFileNamenew, ".bmp");
            writeGSBMP(imageFileNamenew, image3);
        }
        void do_Something_For_Image_mer()                    // merging 2 images by adding every pixel of the 2 images together 
        {                                                     // and dividing it by 2 getting the mixed version of the pixels
            for (int i = 0; i < SIZE; i++) 
            {
                for (int j = 0; j< SIZE; j++)
                {
                    image3[i][j]=(image[i][j]+image2[i][j])/2;
                }  
            }
        }
};

//--------------------------------------------- fliping image 

class filter_flip
{
    private:
        unsigned char image[SIZE][SIZE];
        char imageFileName[100];
        unsigned char flipp[SIZE][SIZE];
        int chos=0;                                               
    public:
        filter_flip(int chos=0):
        chos(chos)
        {
        }
        void st_chos()
        {
            cout<<" Enter 1 to Flip the image horizontally or 2 to Flip the image vertically: ";
            cin>>chos;
            //return chos;
        }
        void saveimage()
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            writeGSBMP(imageFileName, image);
        }
        void loadimage()
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            if(readGSBMP(imageFileName, image)==1)main();
        }
        void do_Something_For_Image_flip()                        //fliping the image by filling the image with pixels either from
        {                                                         //down to up or from right to left
            if(chos==1)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j<= 127; j++)
                    {
                        flipp[i][j]=image[i][j];
                        image[i][j]=image[i][255-j];
                        image[i][255-j]=flipp[i][j];
                    }
                }
            }
            else if(chos==2)
            {
                for (int i = 0; i <=127; i++) 
                {
                    for (int j = 0; j< SIZE; j++) 
                    {
                        flipp[i][j]=image[i][j];
                        image[i][j]=image[255-i][j];
                        image[255-i][j]=flipp[i][j];
                    }
                }
            }
        }
};

//----------------------------------------- rotating image

class filter_rotate
{
    private:
        unsigned char image[SIZE][SIZE];
        unsigned char image2[SIZE][SIZE];
        char imageFileName[100];
        char imageFileName2[100];
        unsigned char flipp[SIZE][SIZE];
        int chos=0;
    public:
        filter_rotate(int chos=0):                                
        chos(chos){   
        }
        void st_chos()
        {
            cout<<"Enter 1 to clockwise by 90 º or Enter 2 to clockwise by 180 º or Enter 3 to clockwise by 270 º: ";
            cin>>chos;
        }
        void loadimage()
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            if(readGSBMP(imageFileName, image)==1)main();
        }
        void saveimage()
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName2;
            strcat (imageFileName2, ".bmp");
            writeGSBMP(imageFileName2, image2);
        }
        void do_Something_For_Image_flip()
        {
            if(chos==1)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j< SIZE; j++)
                    {
                        image2[i][j]=image[j][255-i];
                    }
                }
            }
            else if(chos==2)                                      // rotating 270 degree by filling image from right to left and
            {                                                     // from down to up
                for (int i = 0; i <SIZE; i++)
                {
                    for (int j = 0; j <SIZE; j++)
                    {
                        image2[i][j]=image[255-i][255-j];
                    }
                }
            }
            else if(chos==3)                                             
            {
                for (int i = 0; i < SIZE; i++) 
                {
                    for (int j = 0; j< SIZE; j++)
                    {
                        image2[i][j]=image[255-j][i];
                    }
                }
            }
        }
};

//------------------------------------------- darkening and lightening image

class filter_darken_and_lighten
{
    private:
        unsigned char image[SIZE][SIZE];
        char imageFileName[100];
        int chos=0;
    public:
        filter_darken_and_lighten(int chos=0):
        chos(chos){   
        }
        void st_chos()
        {
            cout<<"Enter 1 to  Darken Image or Enter 2 to  Lighten Image ";
            cin>>chos;
        }
        void loadImage()
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            if(readGSBMP(imageFileName, image)==1)main();
        }
        void saveimage()
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            writeGSBMP(imageFileName, image);
        }
        void do_Something_For_Image_dar_whit()                      // we darken images 50% by dividing each pixel by 2
        {                                                           // and lighten them by adding half of the pixel to itself
            if(chos==1)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < SIZE; j++)
                    {
                        if (image[i][j]==0)
                        {
                            continue;
                        }
                            image[i][j]=(image[i][j])/2;
                    }
                }
            }
            else if(chos==2)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < SIZE; j++)
                    {
                        if (image[i][j]+(image[i][j]/2)>=255)
                        {
                            image[i][j]=255;
                        }
                        else
                            image[i][j]+=(image[i][j]/2);
                    }
                }            
            }
        }
};

//------------------------------------------- Detect Image Edges

class Detect_Image_Edges
{
    private:
        unsigned char image[SIZE][SIZE];
        unsigned char image2[SIZE][SIZE];
        char imageFileName[100];
    public:
        void loadImage()
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            if(readGSBMP(imageFileName, image)==1)main();
        }
        void saveimage()
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            writeGSBMP(imageFileName, image2);
        } 
        void do_Something_For_Detect_Image_Edges()
        {
            int gx,gy;
            for (int i = 0; i < SIZE-2; i++)
            {
                for (int j = 0; j < SIZE-2; j++)
                {
                    gx=((2*image[i+2][j+1])+image[i+2][j]+image[i+2][j+2])-(2*image[i][j+1]+image[i][j]+image[i][j+2]);
                    gy=((2*image[i+1][j+2])+image[i][j+2]+image[i+2][j+2])-(2*image[i+1][j]+(image[i][j])+image[i+2][j]);
                    gx*=gx;
                    gy*=gy;
                    image2[i][j]=sqrt(gx+gy);
                    if(image2[i][j]<=100)image2[i][j]=250;
                    else image2[i][j]=0;
                }
            
            }
        }
                        
};

//------------------------------------------ shrinking image

class shrink_image
{
    private:
        unsigned char image [SIZE][SIZE];
        unsigned char image2 [SIZE][SIZE];
        char imageFileName [100];
        int chos , cnt ,tmp;
    public:
        shrink_image(int chos=0):
            chos(chos)
            {
            cnt=0;
            tmp=0;
        }
        
        void st_chos()
        {
            cout<<"Enter 1 to  shrink Image by 1/2 or Enter 2 to shrink by 1/3 or enter 3 to shrink by 1/4 : ";
            cin>>chos;
        }
        void loadImage()
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            if(readGSBMP(imageFileName, image)==1)main();
        }
        void saveimage()
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            writeGSBMP(imageFileName, image2);
        }
        void do_something_shrink()
        { 
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE  ; j++)
                {
                    if(image2[i][j]==0)image2[i][j]=255;
                }
            }        
                                                                           // we shrink image by getting the average of pixels and putting it
            if (chos==1)                                                   // in the same place in another image
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < SIZE  ; j++)
                    {
                        cnt+=1;    // a counter to tell when to get the average of pixels 
                        tmp+=image[i][j]; // adding pixels to a temp to get average from
                        if (cnt%2==0)
                        {
                            image2[i/2][j/2]=(tmp)/2;
                            tmp=0;
                        }
                        
                    }
                }
            }
            else if (chos==2)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < SIZE  ; j++)
                    {
                        cnt+=1;
                        tmp+=image[i][j];
                        if (cnt%3==0)
                        {
                            image2[i/3][j/3]=(tmp)/3;
                            tmp=0;
                        }
                        
                    }
                        
                }
            }
            else if (chos==3)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j < SIZE  ; j++)
                    {
                        cnt+=1;
                        tmp+=image[i][j];
                        if (cnt%4==0)
                        {
                            image2[i/4][j/4]=(tmp)/4;
                            tmp=0;
                        }
                        
                    }
                }
            }
        }
};

//------------------------------------------ Mirror Image

class mirror_Image
{
private:
    unsigned char image[SIZE][SIZE];
    unsigned char image2[SIZE][SIZE];
    char imageFileName[100];
    int chos;
public:
    mirror_Image(int chos=0):
    chos(chos)
    {
    }
    void st_chos()
    {
        cout<<"To miror image : enter 1 for left 1/2 or 2 for right 1/2 or 3 for the upper 1/2 or 4 for the lower 1/2 : ";
        cin>>chos;
    }
    void loadImage()
    {
        cout << "Enter the source image file name: ";
        cin >> imageFileName;
        strcat (imageFileName, ".bmp");
        if(readGSBMP(imageFileName, image)==1)main();
    }
    void saveimage()
    {
        cout << "Enter the target image file name: ";
        cin >> imageFileName;
        strcat (imageFileName, ".bmp");
        writeGSBMP (imageFileName,image2);
    }
    void do_something_miror()
    {
        if (chos==1)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if ( j<127)
                    {
                        image2[i][j]=image[i][j];
                    }
                    else if (j>=127)
                    {
                        image2[i][j]=image[i][255-j];                  // filling the image in the second half in a descending order
                    }
                    
                }
                
            }
            
        }
        else if (chos==2)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if ( j<127)
                    {
                        image2[i][j]=image[i][255-j];                // filling the image in the first half in an ascending order
                    }
                    else if (j>=127)
                    {
                        image2[i][j]=image[i][j];
                    }
                    
                }
                
            }
            
        }
        else if (chos==3)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if ( i<127)
                    {
                        image2[i][j]=image[i][j];                
                    }
                    else if (i>=127)
                    {
                        image2[i][j]=image[255-i][j];               // filling the image int the upper half in adescending order
                    }
                }
                
            }
            
        }
        else if (chos==4)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if ( i<127)
                    {
                        image2[i][j]=image[255-i][j];               // filling the image int the lower half in an ascending order
                    }
                    else if (i>=127)
                    {
                        image2[i][j]=image[i][j];
                    }
                }  
            }
        }
    }
};

//------------------------------------------ enlarge Image

class enlarge_image
{
    private:
        unsigned char image [SIZE][SIZE];
        unsigned char image2 [SIZE][SIZE];
        char imageFileName [100];
        int chos;
    public:
        enlarge_image(int chos=0):
            chos(chos)
        {
        }
        
        void st_chos()
        {
            cout<<"Enter 1 to enlarge image to the first quarter or Enter 2 to enlarge image to the second quarter or Enter 3 to enlarge image to the third quarter or Enter 4 to enlarge image to the fourth quarter: ";
            cin>>chos;
        }
        void loadImage()
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            if(readGSBMP(imageFileName, image)==1)main();
        }
        void saveimage()
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            writeGSBMP(imageFileName, image2);
        }
        void do_something_enlarge_image()
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE  ; j++)
                {
                    if(image2[i][j]==0)
                    {
                        image2[i][j]=255;      // turning backgroud into white
                    }
                }
            }    
            if(chos==1)  // parts
            {
                for(int i = 0 ; i < SIZE ; i++)
                {
                    for(int j = 0 ; j < SIZE ; j++)
                    {
                        image2[i][j]=image[i/2][j/2];   // making 1 pixel to be filled twice hence taking double its size
                    }
                }
            }
            else if(chos==2)
            {
                for(int i =0  ; i <SIZE ; i++)
                {
                    for(int j = 0 ; j < SIZE; j++)
                    {
                        image2[i][j]=image[i/2][(j+250)/2];
                    }
                }
            }
            else if(chos==3)
            {
                for(int i =0  ; i <SIZE ; i++)
                {
                    for(int j = 0 ; j < SIZE; j++)
                    {
                        image2[i][j]=image[(i+250)/2][j/2];
                    }
                }
            }
            
            else if(chos==4)
            {
                for(int i =0  ; i <SIZE ; i++)
                {
                    for(int j = 0 ; j < SIZE; j++)
                    {
                        image2[i][j]=image[(i+250)/2][(j+250)/2];
                    }
                }
            }
            
        }
};

//------------------------------------------ shuffle Image

class shufle_image
{
    private:
        unsigned char image [SIZE][SIZE];
        unsigned char frt [SIZE/2][SIZE/2];
        unsigned char sec [SIZE/2][SIZE/2];
        unsigned char third [SIZE/2][SIZE/2];
        unsigned char forth [SIZE/2][SIZE/2];
        unsigned char image2 [SIZE][SIZE];
        int x,y,z,w;
        char imageFileName [100];
    public:
        shufle_image(int x=0,int y=0,int z=0,int w=0):
        x(x),y(y),z(z),w(w)
        {
        }
        void st_ord()
        {
            //order variables
            cout<<"Enter the order wants to quarters in the new: ";
            cin>>x>>y>>z>>w;
        }
        void loadImage()
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            if(readGSBMP(imageFileName, image)==1)main();
        }
        void saveimage()
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            writeGSBMP(imageFileName, image2);
        }
        void do_something_shuffle_image()
        {
            // cutting the parts
            for(int i = 0 ; i < 127 ; i++)
            {
                for(int j = 0 ; j < 127 ; j++)
                {
                    frt[i][j]=image[i][j];
                }
            }
            for(int i = 0 ; i < 127 ; i++)
            {
                for(int j = 127 ; j < SIZE ; j++)
                {
                    sec[i][j-127]=image[i][j];
                }
            }
            for(int i = 127 ; i < SIZE ; i++)
            {
                for(int j = 0 ; j < 127 ; j++)
                {
                    third[i-127][j]=image[i][j];
                }
            }
            for(int i = 127 ; i < SIZE ; i++)
            {
                for(int j = 127 ; j < SIZE ; j++)
                {
                    forth[i-127][j-127]=image[i][j];
                }
            }
            // ordering parts
            if(x==1)  // first quarter
                {
                    for(int i = 0 ; i < 127 ; i++)
                    {
                        for(int j = 0 ; j < 127  ; j++)
                        {
                            image2[i][j]=frt[i][j];
                        }
                    }
                }
                else if(x==2)
                {
                    for(int i = 0 ; i < 127 ; i++)
                    {
                        for(int j = 0 ; j < 127  ; j++)
                        {
                            image2[i][j]=sec[i][j];
                        }
                    }
                }
                else if(x==3)
                {
                    for(int i = 0 ; i < 127 ; i++)
                    {
                        for(int j = 0 ; j < 127  ; j++)
                        {
                            image2[i][j]=third[i][j];
                        }
                    }
                }
                else if(x==4)
                {
                    for(int i = 0 ; i < 127 ; i++)
                    {
                        for(int j = 0 ; j < 127  ; j++)
                        {
                            image2[i][j]=forth[i][j];
                        }
                    }
                }
            if(y==1)  // second quarter
            {
                for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i][j+127]=frt[i][j];
                    }
                }
            }
            else if(y==2)
            {
               for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i][j+127]=sec[i][j];
                    }
                }
            }
            else if(y==3)
            {
                for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i][j+127]=third[i][j];
                    }
                }
            }
            else if(y==4)
            {
                for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                    image2[i][j+127]=forth[i][j];
                    }
                }
            }
            if(z==1)  // gthird quarter
            {
                for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i+127][j]=frt[i][j];
                    }
                }
            }
            else if(z==2)
            {
                for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i+127][j]=sec[i][j];
                    }
                }
            }
            else if(z==3)
            {
            for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i+127][j]=third[i][j];
                    }
                }
            }
            else if(z==4)
            {
                for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i+127][j]=forth[i][j];
                    }
                }
            }
            if(w==1)  // fourth quarter
            {
                for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i+127][j+127]=frt[i][j];
                    }
                }
            }
            else if(w==2)
            {
                for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i+127][j+127]=sec[i][j];
                    }
                }
            }
            else if(w==3)
            {
                for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i+127][j+127]=third[i][j];
                    }
                }
            }
            else if(w==4)
            {
                for(int i = 0 ; i < 127 ; i++)
                {
                    for(int j = 0 ; j < 127  ; j++)
                    {
                        image2[i+127][j+127]=forth[i][j];
                    }
                }
            }
        }

};

//----------------------------------------- blur image

class blur_image
{
private:
    unsigned char image[SIZE][SIZE] , image2[SIZE][SIZE] ;
    char imageFileName [100];
    int l;
public:
    void loadImage()
    {
        cout << "Enter the source image file name: ";
        cin >> imageFileName;
        strcat (imageFileName, ".bmp");
        if(readGSBMP(imageFileName, image)==1)main();
    }
    void saveimage()
    {
        cout << "Enter the target image file name: ";
        cin >> imageFileName;
        strcat (imageFileName, ".bmp");
        writeGSBMP (imageFileName, image2);
    }
    void do_Something_blur()
    {
        int l;
        for (int i = 1 ; i < SIZE ; i++)
        {
            for(int j =1 ; j <SIZE ; j++)
            {
                // bluring is done by taking a matrix of pixels 3x3 and dividing it by 9 
                l =((image[i-1][j] + image[i][j] + image[i+1][j] + image[i-1][j-1] + image[i][j-1] +
                     image[i+1][j-1]+image[i-1][j+1] + image[i][j+1] + image[i+1][j+1]) / 9);
                image2[i][j] =l ;
            }
        }

    }    
};

//------------------------------------------ crop image

class crop_image
{
    private:
        unsigned char image [SIZE][SIZE] , image2 [SIZE][SIZE] ;
        char imageFileName [100];
        int l, w , x , y , tmp , tmp2 ,ytmp;
    public:
        crop_image(int x=0,int y=0,int l=0 ,int w=0):
        x(x),y(y),l(l),w(w)
        {

        }
        void st_chos()
        {
            cout<<"Please enter the positions to crop (x , y) and the length of the image you want (l , w) : ";
            cin>>x>>y>>l>>w;
        }
        void loadImage()
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            readGSBMP(imageFileName, image);
        }
        void saveimage()
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            writeGSBMP (imageFileName , image2);
        }
        void do_Something_crop()
        {
            //making the figure white
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    image2[i][j]=255;
                }
            }
            tmp=(SIZE-l)/2; // the remaning part from subtracting the wanted legnth from the whole length the dividing to get the removed length 
            ytmp=y;    // temp used as the starting point of the pixels wanted from user to not change the starting point while looping
            tmp2=(SIZE-w)/2; // the remaning part from subtracting the wanted width from the whole width the dividing to get the removed width 
            for (int i = tmp2; i < SIZE; i++)
            {
                for (int j = tmp; j < SIZE; j++)
                {
                    image2[i][j]=image[x][ytmp];            //putting the pixels chosen in the edited image
                    ytmp++;
                    if (j==l+(SIZE-l)/2 )                  // checking if the pixels reached the given length 
                    {
                        break;
                    }
                }
                if (i==w+(SIZE-w)/2)                       //checking if pixels reached the given width
                {
                    break;
                }
                x++;
                ytmp=y;
            }
        }
};

//------------------------------------------ SKew image

class skew
{
    private:
        unsigned char image [SIZE][SIZE];
        unsigned char image2 [SIZE][SIZE];
        unsigned char image3 [SIZE][SIZE];
        char imageFileName [100];
        double degree;  // degree of skew
    public:
        skew(double degree=0):
            degree(degree)
        {
            
        }
        void st_degree()
        {
            cout<<"Enter the degree ]0,90[ : ";
            cin>>degree;
        }
        void loadImage()
        {
            cout << "Enter the source image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            if(readGSBMP(imageFileName, image)==1)main();
        }
        void saveimage()
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName;
            strcat (imageFileName, ".bmp");
            writeGSBMP (imageFileName,image3);
        }
        void do_something_skew_horizontal()
        {
            //double rad=tan(degree);
            double rad=(degree*22)/(7*180);  // converting to radius
            double xx=256/(1+1/tan(rad));
            double stp=256-int(xx);   // movement of image
            double mov=stp/SIZE;
            for(int i = 0 ; i < SIZE ; i++)
            {
                for(int j = 0 ; j < SIZE ; j++)
                {
                    image2[i][j]=255;    // converting background to white
                    image3[i][j]=255;
                }
            }
            for(int i = 0 ; i < SIZE ; i++)
            {
                for(int j = 0 ; j < SIZE ; j++)
                {
                    image2[i][(j*int(xx))/SIZE]=image[i][j];  // shrink depend on degree
                }
            }
            for(int i = 0 ; i < SIZE ; i++)
            {
                for(int j = 0 ; j < SIZE ; j++)
                {
                    image3[i][j+int(stp)]=image2[i][j];
                }stp-=mov;
            }
        }
        void do_something_skew_vertically()
        {
            double rad=((90-degree)*22)/(7*180);
            double xx=256/(1+tan(rad));
            double stp=256-xx;
            double mov=stp/SIZE;
            for(int i = 0 ; i < SIZE ; i++)
            {
                for(int j = 0 ; j < SIZE ; j++)
                {
                    image2[i][j]=255;
                    image3[i][j]=255;
                }
            }
            for(int i = 0 ; i < SIZE ; i++)
            {
                for(int j = 0 ; j < SIZE ; j++)
                {
                    image2[i*int(xx)/SIZE][j]=image[i][j];//shrink depend on degree
                }
            }
            double x=stp;
            int c=0;
            for(int i = 0 ; i < SIZE ; i++)
            {
                if(i+int(stp)>256)break;
                for(int j = 0 ; j < SIZE ; j++)
                {
                    image3[i+int(stp)][j]=image2[i][j];  // movement
                    stp-=mov;
                }
                stp=x;
            }
        }
};

//------------------------------------------ main function

int main(){
    while (chose!='0')
    {
        cout<<"Enter 1 to make filter Black and White\nEnter 2 to make filter Invert Image\nEnter 3 to make filter Merge Images\nEnter 4 to make filter Flip Image\n";
        cout<<"Enter 5 to make filter Rotate Image\nEnter 6 to make filter Darken and Lighten Image\n";
        cout<<"Enter 7 to make filter Detect Image Edges\nEnter 8 to make Enlarge Image\nEnter 9 to make Shrink Image\n";
        cout<<"Enter (a) to make Mirror Image\nEnter (b) to make Shuffle Image\nEnter (c) to make Blur Image\nEnter (d) to make Crop Image\n";
        cout<<"Enter (e) to make Skew Horizontally\nEnter (f) to make Skew Vertically\n";
        cout<<"Enter 0 to Exit:  \n";
        cin>>chose;
        if(chose=='0')  return 0;
        while(check_number(chose)==false)
        {
            cout<<"!! Enter Between Options !!"<<endl;
            cout<<"Enter 1 to make filter Black and White\nEnter 2 to make filter Invert Image\nEnter 3 to make filter Merge Images\nEnter 4 to make filter Flip Image\n";
            cout<<"Enter 5 to make filter Rotate Image\nEnter 6 to make filter Darken and Lighten Image\n";
            cout<<"Enter 7 to make filter Detect Image Edges\nEnter 8 to make Enlarge Image\nEnter 9 to make Shrink Image\n";
            cout<<"Enter (a) to make Mirror Image\nEnter (b) to make Shuffle Image\nEnter (c) to make Blur Image\nEnter (d) to make Crop Image\n";
            cout<<"Enter (e) to make Skew Horizontally\nEnter (f) to make Skew Vertically\n";
            cout<<"Enter 0 to Exit:  \n";
            cin>>chose;
            if(chose=='0')  return 0;
        }
            chosing();
  }
  return 0;
}
bool check_number(char chos)
{
    for(int i=0;i<15;i++)
    {
        if(chos==options[i])
        {
            return true;
        }
    }return false;
}
//------------------------------------------- choosing the filter
void chosing()
{
    if(chose=='1')
    {
        filter_BW bw;
        bw.loadImage();
        bw.doSomethingForImageBW();
        bw.saveimage();
     }
     else if(chose=='2')
     {
        filter_inv inv;
        inv.loadImage();
        inv.doSomethingForImageinv();
        inv.saveimage();
    }
    else if(chose=='3')
    {
        filter_merg mer;
        mer.load_Image();
        mer.do_Something_For_Image_mer();
        mer.save_image();
    }
    else if(chose=='4')
    {
        filter_flip flp;
        flp.loadimage();
        flp.st_chos();
        flp.do_Something_For_Image_flip();
        flp.saveimage();
    }
    else if(chose=='5')
    {
        filter_rotate rot;
        rot.loadimage();
        rot.st_chos();
        rot.do_Something_For_Image_flip();
        rot.saveimage();
    }
    else if(chose=='6')
    {
        filter_darken_and_lighten dl;
        // dl.loadimage();
        dl.loadImage();
        dl.st_chos();
        dl.do_Something_For_Image_dar_whit();
        dl.saveimage();
    }
    else if(chose=='7')
    {
        Detect_Image_Edges dd1;
        dd1.loadImage();
        dd1.do_Something_For_Detect_Image_Edges();
        dd1.saveimage();
    }
    else if(chose=='8')
    {
        enlarge_image en;
        en.loadImage();
        en.st_chos();
        en.do_something_enlarge_image();
        en.saveimage();
    }
    else if(chose=='9')
    {
        shrink_image sh;
        sh.loadImage();
        sh.st_chos();
        sh.do_something_shrink();
        sh.saveimage();
    }
    else if(chose=='a')
    {
        mirror_Image mmi;
        mmi.st_chos();
        mmi.loadImage();
        mmi.do_something_miror();
        mmi.saveimage();
    }
    else if(chose=='b')
    {
        shufle_image shf;
        shf.loadImage();
        shf.st_ord();
        shf.do_something_shuffle_image();
        shf.saveimage();
    }
    else if(chose=='c')
    {
        blur_image ci;
        ci.loadImage();
        ci.do_Something_blur();
        ci.saveimage();

    }
    else if(chose=='d')
    {
        crop_image cimg;
        cimg.loadImage();
        cimg.st_chos();
        cimg.do_Something_crop();
        cimg.saveimage();
    }
    else if(chose=='e')
    {
        skew sk;
        sk.loadImage();
        sk.st_degree();
        sk.do_something_skew_horizontal();
        sk.saveimage();
    }
    else if(chose=='f')
    {
        skew skv;
        skv.loadImage();
        skv.st_degree();
        skv.do_something_skew_vertically();
        skv.saveimage();
    }

}
