typedef struct hotel{
    char name[128];
    char address[256];
    int grade;
    int num_rooms;
    int room_charges;
}hotel;

void init(hotel *list, char *name, char* address, int grade, int num_rooms, int charge);
void get_by_grade(hotel *list, int list_size, int grade);
void get_by_charge(hotel *list, int list_size, int charge);