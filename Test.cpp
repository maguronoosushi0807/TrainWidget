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
    // load
    schedule_t ItW[MAX_HOURS][MAX_MINS] = {};
    schedule_t WtI[MAX_HOURS][MAX_MINS] = {};
    schedule_t MtW[MAX_HOURS][MAX_MINS] = {};
    schedule_t WtM[MAX_HOURS][MAX_MINS] = {};

    store_schedule("ItW.csv", ItW);
    store_schedule("WtI.csv", WtI);
    store_schedule("MtW.csv", MtW);
    store_schedule("WtM.csv", WtM);



    // input
    char location = 'i', destiny = 'w';
    string time = "";

    cout << "Where r u? (1 character)" << endl << "< ";
    cin >> location;
    cout << "Where r u goint to? (1 character)" << endl << "< ";
    cin >> destiny;
    cout << "What time is it now? (xx:xx)" << endl << "< ";
    cin >> time;
    if((location != 'i' && location != 'w' && location != 'm') || (destiny != 'i' && destiny != 'w' && destiny != 'm')){
        cout << "invalid input" << endl;
        return -1;
    }



    // convert
    vector<schedule_t(*)[MAX_MINS]>schedule;
    if(location == 'i'){
        schedule.emplace_back(ItW);
        if(destiny == 'm'){
            schedule.emplace_back(WtM);
        }
    }else if(location == 'w'){
        if(destiny == 'i'){
            schedule.emplace_back(WtM);
        }else if(destiny == 'm'){
            schedule.emplace_back(WtM);
        }
    }else if(location == 'm'){
        schedule.emplace_back(MtW);
        if(destiny == 'i'){
            schedule.emplace_back(WtI);
        }
    }
    // for(auto s:schedule) load_test(s);


    vector<schedule_t> depart;
    int input_hour = stoi(time.substr(0,2));
    int input_min = stoi(time.substr(3,2));
    cout << "hour:" << input_hour << " min:" << input_min << endl;



    // search
    bool is_searched = false;
    for(int k=0;k<schedule.size();k++){
        is_searched = false;
        for(int j=0;j<MAX_HOURS;j++){
            for(int i=0;i<MAX_MINS;i++){
                if(schedule[k][j][i].hour * 100 + schedule[k][j][i].min >= input_hour * 100 + input_min){
                    // cout << schedule[k][j][i].hour << ":" << schedule[k][j][i].min << endl;
                    schedule_t s;
                    s.hour     = schedule[k][j][i].hour;
                    s.min      = schedule[k][j][i].min;
                    s.is_rapid = schedule[k][j][i].is_rapid;
                    depart.push_back(s);

                    is_searched = true;
                    break;
                }
            }
            if(is_searched) break;
        }
    }
    if(!is_searched)    cout << "no train!w";

    for(auto s:depart) cout << s.hour << ":" << s.min << " " << s.is_rapid << endl;



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