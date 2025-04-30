// program to find the area of square, cube, ectangle, cuboid

#include <cstdio>

class area
{
    private:
    int len, wid, hei;

    public:
        area()
        {
            len = 1;
            wid = 1;
            hei = 1;
        }
        void set_len(int);
        void set_wid(int);
        void set_hei(int);
        int square();
        int cube();
        int rectangle();
        int cuboid();
};

int main()
{
    int len,wid,hei;

    int chc;
    do 
    {
        printf("enter 1. for area of square, 2. for area of cube, 3. for area of rectangle, 4. for area of cuboid, 5. for exit\n");
        scanf("%d", &chc);
        area obj;
        switch(chc)
        {
            case 1:
                printf("enter the length: ");
                scanf("%d", &len);
                if (len>0)
                {
                    obj.set_len(len);
                    printf("area of the square: %d \n", obj.square());
                }
                else
                {
                    printf("invalid input\n");
                }
                break;
            case 2:
                printf("enter the length: ");
                scanf("%d", &len);
                if (len>0)
                {
                    obj.set_len(len);
                    printf("area of the cube: %d \n", obj.cube());
                }
                else
                {
                    printf("invalid input\n");
                }
                break;
            case 3:
                printf("enter the length and width: ");
                scanf("%d %d", &len, &wid);
                if (len>0&&wid>0)
                {
                    obj.set_len(len);
                    obj.set_wid(wid);
                    printf("area of the rectangle: %d \n", obj.rectangle());
                }
                else
                {
                    printf("invalid input\n");
                }
                break;
            case 4:
                printf("enter the length, width and height: ");
                scanf("%d %d %d", &len, &wid, &hei);
                if (len>0&&wid>0&&hei>0)
                {
                    obj.set_len(len);
                    obj.set_wid(wid);
                    obj.set_hei(hei);
                    printf("area of the cuboid: %d \n", obj.cuboid());
                }
                else
                {
                    printf("invalid input\n");
                }
            case 5:
                return 0;
            default:
                printf("invalid input. please enter a valid choice\n");

        }
    }while(chc<5);
    
}

void area::set_len(int len1)
{
    len=len1;
}

void area::set_wid(int wid1)
{
    wid=wid1;
}

void area::set_hei(int hei1)
{
    hei=hei1;
}

int area::square()
{
    return len*len;
}

int area::cube()
{
    return 6*len*len;
}

int area::rectangle()
{
    return len*wid;
}

int area::cuboid()
{
    return 2*(len*wid + len*hei + hei*wid);
}
