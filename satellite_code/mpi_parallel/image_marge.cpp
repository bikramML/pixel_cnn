
class serial_image_matrix
{
public:
    uint32 rows=0,colums=0;
    double** p;
    serial_image_matrix(double **m,uint32 r,uint32 c)
    {
        p=m;
        rows=r;colums=c;

    }
    serial_image_matrix(uint32 r,uint32 c)
    {
        rows=r;colums=c;
    }
    double** matrix_scale_up(double scaler)
    {
        uint16 i,j;
        double** r=new double*[rows];
        //cout<<rows<<"\t"<<colum;
        for(i=0;i<rows;i++)
        {
            r[i]=new double[colums];
            for(j=0;j<colums;j++)
            {
                r[i][j]=p[i][j]*scaler;
            }
        }
        return r;
    }

    double** operator+(const double& s)
    {
        uint16 i,j;
        double** r=new double*[rows];
        for(i=0;i<rows;i++)
        {
            r[i]=new double[colums];
            for(j=0;j<colums;j++)
            {
                r[i][j]=p[i][j]+s;
            }
        }
        return r;
    }
    serial_image_matrix operator+(const serial_image_matrix& m)
    {
        uint16 i,j;

        if((m.rows!=rows)||(m.colums!=colums))
        {
            cout<<"Matrix size miss mach";
            exit(0);
            //return this*;
        }
        serial_image_matrix r(rows,colums);
         r.p=new double*[rows];
        for(i=0;i<rows;i++)
        {
            r.p[i]=new double[colums];
            for(j=0;j<colums;j++)
            {
                r.p[i][j]=m.p[i][j]+p[i][j];
            }
        }
        return r;
    }
    void operator=(const serial_image_matrix& m)
    {
        this->colums=m.colums;
        this->rows=m.colums;
        this->p=m.p;
    }
    void matrix_size_incr(uint16 t_x,uint16 t_y)
    {
        uint16 r_x=t_x/rows,r_y=t_y/colums,i,j,k,l;
        double** r=new double*[t_x];
        for(i=0;i<t_x;i++)r[i]=new double[t_y]();

        for(k=0;k<rows;k++)
            for(l=0;l<colums;l++)
                for(i=0;i<r_x;i++)
                    for(j=0;j<r_y;j++)
                    {
                        r[k+i][l+j]=p[k][l];
                    }
        delete[] p;
        rows=t_x;colums=t_y;
        p=r;
        //return r;
    }

};

