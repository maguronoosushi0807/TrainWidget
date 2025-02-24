#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;




constexpr auto MAX_HOURS = 24;
constexpr auto MAX_MINS = 5;
struct schedule_t{
    int hour = 0;
    int min = 0;
    bool is_rapid = false;
};

vector<string> split(string& input, char delimiter);

void store_schedule(string file_name, schedule_t schedule[][MAX_MINS]);
void load_test(schedule_t schedule[][MAX_MINS]);





int main(){
    schedule_t ItW[MAX_HOURS][MAX_MINS] = {};
    schedule_t WtI[MAX_HOURS][MAX_MINS] = {};
    schedule_t MtW[MAX_HOURS][MAX_MINS] = {};
    schedule_t WtM[MAX_HOURS][MAX_MINS] = {};

    store_schedule("ItW.csv", ItW);
    store_schedule("WtI.csv", WtI);
    store_schedule("MtW.csv", MtW);
    store_schedule("WtM.csv", WtM);



    char location = 'i', destiny = 'w';
    string time = "";

    cout << "Where r u?" << endl << "< ";
    cin >> location;
    cout << "Where r u goint to?" << endl << "< ";
    cin >> destiny;
    cout << "What time is it now?" << endl << "< ";
    cin >> time;

    schedule_t (*schedule)[MAX_MINS] = nullptr;
    if(location == 'i' && destiny == 'w')       schedule = ItW;
    else if(location == 'w' && destiny == 'i')  schedule = WtI;
    else if(location == 'm' && destiny == 'w')  schedule = MtW;
    else if(location == 'w' && destiny == 'm')  schedule = WtM;
    else{
        cout << "invalid input" << endl;
        return -1;
    }

    load_test(schedule);



    return 0;
}



void store_schedule(string file_name, schedule_t schedule[][MAX_MINS]){
    ifstream file(file_name);
    string line;
    while(getline(file, line)){
        vector<string> vec = split(line, ',');
        
        int count = 0;
        for(auto v:vec){
            bool is_rapid = (v.at(0) == '_');
            if(is_rapid) v.erase(0, 1);

            int hour = stoi(v.substr(0,2));
            int min  = stoi(v.substr(2,2));

            schedule[hour-1][count].hour     = hour;
            schedule[hour-1][count].min      = min;
            schedule[hour-1][count].is_rapid = is_rapid;
            
            count++;
        }
    }

    return;
}

void load_test(schedule_t schedule[][MAX_MINS]){
    // output
    for(int j=0;j < MAX_HOURS;j++){
        int hour = schedule[j][0].hour;
        for(int i=0;i<MAX_MINS;i++){
            int min  = schedule[j][i].min;

            if(hour != 0 && min != 0){
                cout << hour << ":" << min << "  ";
            }

        }
        if(hour != 0) cout << "\n";
    }
    
    return;
}




vector<string> split(string& input, char delimiter)
{
    istringstream stream(input);
    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}