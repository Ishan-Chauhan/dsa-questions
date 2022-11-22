class ParkingSystem {
public:
    int b,m,s;
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
    }
    
    bool addCar(int t) {
        if(t==1)
        {
            if(b>0)
            {
                b--;
                return true;
            }
            return false;
        }
        else if(t==2)
        {
            if(m>0)
            {
                m--;
                return true;
            }
            return false;
        }
        else
        {
            if(s>0)   
            {
                s--;
                return true;
            }
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */