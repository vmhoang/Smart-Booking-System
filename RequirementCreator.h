#ifndef REQUIREMENTCREATOR_H_
#define REQUIREMENTCREATOR_H_
class RequirementCreator{
    private:
    int budget;
        string hotelType;
        int gamenum;
        int customercounter = 0;
        CustomerRequirement *list;
    public:
        RequirementCreator(){
            list = new CustomerRequirement[MAXREQUIREMENTS];
        }
        void createCutomerBundle();
        void writeBundle();
};
    void RequirementCreator::createCutomerBundle(){
         ifstream file;
        char comma;
        file.open("requirementList.txt");
        
        while (file >> budget >> hotelType>> comma)
        {
            if(comma == '['){
                do{
                    file >> gamenum >> comma;
                    list[customercounter].games[gamenum] = true;
                }while(comma != ']');
            }
            hotelType.erase(hotelType.begin());
            list[customercounter].budget = budget;
            list[customercounter].hotelType = hotelType;
            list[customercounter].cId = customercounter;
            customercounter += 1;
        }
        file.close();
    }
    void RequirementCreator::writeBundle(){
        for (int  i =0 ;  i < customercounter; i++){
            cout << "Customer No " << list[i].cId << " budget " << list[i].budget << " hotel "
                    << list[i].hotelType << " events ";
            for (int n = 0; n < NUMBEROFGAMES; n++){
                if (list[i].games[n] == true){
                    cout << setw(5) << n ;
                }
            }
            cout << endl;
        }
        
        cout << "Customer request number generated. Check the file!" << endl;
    }
#endif