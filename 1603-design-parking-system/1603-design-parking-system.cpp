class ParkingSystem {
public:
vector<int> temp;
    ParkingSystem(int big, int medium, int small) {
        temp = vector<int> {big,medium,small};
    }
    
    bool addCar(int carType) {
        if (temp[carType - 1] > 0) {
            temp[carType - 1]--;
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */