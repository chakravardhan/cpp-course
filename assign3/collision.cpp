class ship {
    public:
    int x, y; //direction var i use
    int radius;
    }ship1, ship2;


int sqrd(int num){ //squares a number
    return (num*num);}

bool check_col(ship* s1, ship*s2){
    int dis; //distance

    dis = abs( sqrt( sqrd(s1->x - s2->x) + sqrd(s1->y - s2->y))); //include cmath
    dis -= s1->radius;
    dis -= s2->radius;

    if (dis<=0) //collision
    return true;

    //no collision
    return false;}

	