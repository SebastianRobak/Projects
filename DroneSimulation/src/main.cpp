#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <list>
#include <memory>

#include "vector.hh"
#include "vector3D.hh"
#include "matrix.hh"
#include "matrix3x3.hh"
#include "cuboid.hh"
#include "gnuplot_link.hh"
#include "Prism.hh"
#include "Figure.hh"
#include "Obstacle.hh"
#include "Drone.hh"
#include "Scene_object.hh"
#include "Scene.hh"
#include "Factory.hh"


using namespace std;


const int xLength=0;
const int yLength=0;
const int zLength=0;
const int kShorterEdgesLength = 20;
const int kLongerEdgesLength = 30;
const int zLonger=20;
const int R=6;
const int Thickness=10;






/*!
 * Zapis wspolrzednych zbioru punktow prostopadloscianu do strumienia wyjściowego.
 * \param[in] output_stream - strumien wyjsciowy, do ktorego maja zostac
 *                            zapisane kolejne wspolrzedne.
 *
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

void Cub_WriteToStream(ostream& output_stream, Cuboid cub)
{

output_stream << cub[0] << endl << cub[1] << endl << endl << cub[3] << endl << cub[2] << endl <<endl;

output_stream << cub[7] << endl << cub[6] << endl << endl << cub[4] << endl << cub[5] << endl <<endl;

output_stream << cub[0] << endl << cub[1] << endl;

output_stream << endl << endl;
}

/*!
 * Zapis wspolrzednych zbioru punktow graniastoslupa do strumienia wyjściowego.
 * \param[in] output_stream - strumien wyjsciowy, do ktorego maja zostac
 *                            zapisane kolejne wspolrzedne.
 *
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void Prism_WriteToStream(ostream& output_stream, Prism prism, Vector3D middlebot)
{
Vector3D middletop;
middletop=middlebot;
middletop[2]=middlebot[2]+(prism[6][2]-prism[0][2]);

for (int i=0; i<6; ++i)
    output_stream << middlebot << endl << prism[i] << endl << prism[i+6] << endl  << middletop << endl <<endl;

output_stream << middlebot << endl << prism[0] << endl << prism[6] << endl  << middletop << endl <<endl;

output_stream << endl << endl;

}


/*!
 * zapis wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] filename - nazwa pliku, do którego zostana zapisane
 *                       wspolrzędne punktów.
 *
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */


bool WriteToFile(string filename, std::list<std::shared_ptr<Scene_object>> List)
{
  ofstream  file_stream;

  file_stream.open(filename);
  if (!file_stream.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

for (std::shared_ptr<Scene_object> obj : L)
  switch (obj.get()->type()){
  case 'd':{Cub_WriteToStream(file_stream,obj.get()->body());

for (int i=0; i<4; ++i)
{
  Prism_WriteToStream(file_stream,obj.get()->rotor(i), obj.get()->body()[i+4]);
}
}
break;
case 'o':{
  Cub_WriteToStream(file_stream,obj.get()->Obst);
}
break;
}

file_stream.close();
  return !file_stream.fail();
}


int main()
{
 PzG::LaczeDoGNUPlota  Lacze;

 /* Lacze.DodajNazwePliku("cuboid.dat");
  Lacze.DodajNazwePliku("Prism1.dat");
  Lacze.DodajNazwePliku("Prism2.dat");
  Lacze.DodajNazwePliku("Prism3.dat");
  Lacze.DodajNazwePliku("Prism4.dat");*/
Lacze.DodajNazwePliku("Scena.dat");
/*
  Lacze.DodajNazwePliku("Drone1.dat");
  Lacze.DodajNazwePliku("Drone2.dat");
  Lacze.DodajNazwePliku("Drone3.dat");
  Lacze.DodajNazwePliku("Obstacle1.dat");
  Lacze.DodajNazwePliku("Obstacle2.dat");
  Lacze.DodajNazwePliku("Obstacle3.dat");
  Lacze.DodajNazwePliku("Obstacle4.dat");
  Lacze.DodajNazwePliku("Obstacle5.dat");
*/
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-200, 200);
  Lacze.UstawZakresY(-200, 200);
  Lacze.UstawZakresZ(-20, 90);


  Lacze.UstawRotacjeXZ(20,20); // Tutaj ustawiany jest widok*/

 //PzG::GnuplotLink  link;

 /* link.AddFilename("cuboid.dat",PzG::LS_CONTINUOUS,2);
  link.AddFilename("cuboid.dat",PzG::LS_SCATTERED,2);
  link.AddFilename("Prism1.dat",PzG::LS_CONTINUOUS,2);
  link.AddFilename("Prism1.dat",PzG::LS_SCATTERED,2);
  link.AddFilename("Prism2.dat",PzG::LS_CONTINUOUS,2);
  link.AddFilename("Prism2.dat",PzG::LS_SCATTERED,2);
  link.AddFilename("Prism3.dat",PzG::LS_CONTINUOUS,2);
  link.AddFilename("Prism3.dat",PzG::LS_SCATTERED,2);
  link.AddFilename("Prism4.dat",PzG::LS_CONTINUOUS,2);
  link.AddFilename("Prism4.dat",PzG::LS_SCATTERED,2);

  link.SetDrawingMode(PzG::DM_3D);
  link.SetRangeY(-50,50);
  link.SetRangeX(-50,50);
  link.SetRangeZ(-50,50);
*/

bool end=true;

char op;

double distance, angle, front_angle=0;
double amount;

double fly_speed, rotor_speed, rotation_speed;

double scale;

double  JumpAngle_degrees =-1*M_PI/3;
int drone_int=0;
Drone drones[3];
Obstacle obst[5];
Vector3D middle;

Scene scene;

Factory Fact;

shared_ptr<Scene_object>  Obj;
Vector3D mid, dim;
mid[0]=-50;
mid[1]=-50;
mid[2]=0;
dim[0]=10;
dim[1]=15;
dim[2]=10;

Obj = Fact.Nazwa("Robot A").StworzObiekt(TO_Robot, mid, dim, 'd');

  scene.objects().push_back(Obj);
   //----------------------------------
   // Jawne rzutowanie w gore
  scene.drones().push_back(static_pointer_cast<Drone>(Obj));
 scene.Drones.back().get()->set_Drone(R, Thickness, JumpAngle_degrees);


/*
  scene.objects().push_back(Fact.Nazwa("Przeszkoda 1").StworzObiekt(TO_Przeszkoda));
  scene.objects().push_back(Fact.Nazwa("Przeszkoda 2").StworzObiekt(TO_Przeszkoda));

  cout << endl << "... Poczatek wyswietlenia listy obiektow graficznych ...." << endl << endl;;

  for (const shared_ptr<Scene_object>  &Obj : scene.objects()) {
    cout << "   Typ: " << Obj->Typ() << " (" << Obj->Nazwa() << ")" << endl;
  }

  cout << endl << "... Koniec wyswietlenia listy obiektow graficznych ......" << endl;


  cout << endl << "... Poczatek wyswietlenia listy robotow ...." << endl << endl;;

  for (const shared_ptr<Drone>  &WRob : scene.drones()) {
    cout << "   Typ: " << WRob->Typ() << " (" << WRob->Nazwa() << ")" << endl;
}
  //Lst_Obiektow.remove(Obj);

 // Obj.reset();

*/


/*

scene.objects.push_back(std::make_shared<Scene_object>(-100,-100,0,20,30,20));
scene.objects.push_back(std::make_shared<Scene_object>(-100,100,0,20,30,20));
scene.objects.push_back(std::make_shared<Scene_object>(100,100,0,20,30,20));
scene.objects.push_back(std::make_shared<Scene_object>(-50,-50,0,10,15,10));

//scene.drones.push_back(static_cast<Drone*>(scene.objects.back()));
shared_ptr<Drone> w=static_pointer_cast<shared_ptr<Drone*>>(scene.objects.back());




scene.objects.push_back(std::make_shared<Scene_object>(0,70,0,10,15,10));
scene.objects.push_back(std::make_shared<Scene_object>(70,0,0,10,15,10));

*/


drones[0].middle_point()[0]=-50;
drones[0].middle_point()[1]=-50;
drones[0].middle_point()[2]=0;
drones[0].dimensions()[0]=10;
drones[0].dimensions()[1]=15;
drones[0].dimensions()[2]=10;

drones[1].middle_point()[0]=0;
drones[1].middle_point()[1]=70;
drones[1].middle_point()[2]=0;
drones[1].dimensions()[0]=10;
drones[1].dimensions()[1]=15;
drones[1].dimensions()[2]=10;

drones[2].middle_point()[0]=70;
drones[2].middle_point()[1]=0;
drones[2].middle_point()[2]=0;
drones[2].dimensions()[0]=10;
drones[2].dimensions()[1]=15;
drones[2].dimensions()[2]=10;

obst[0].middle_point()[0]=-100;
obst[0].middle_point()[1]=-100;
obst[0].middle_point()[2]=0;
obst[0].dimensions()[0]=20;
obst[0].dimensions()[1]=30;
obst[0].dimensions()[2]=20;

obst[1].middle_point()[0]=-100;
obst[1].middle_point()[1]=100;
obst[1].middle_point()[2]=0;
obst[1].dimensions()[0]=20;
obst[1].dimensions()[1]=30;
obst[1].dimensions()[2]=20;

obst[2].middle_point()[0]=100;
obst[2].middle_point()[1]=100;
obst[2].middle_point()[2]=0;
obst[2].dimensions()[0]=20;
obst[2].dimensions()[1]=30;
obst[2].dimensions()[2]=20;



obst[3].middle_point()[0]=-70;
obst[3].middle_point()[1]=-70;
obst[3].middle_point()[2]=40;
obst[3].dimensions()[0]=5;
obst[3].dimensions()[1]=5;
obst[3].dimensions()[2]=40;

obst[4].middle_point()[0]=40;
obst[4].middle_point()[1]=70;
obst[4].middle_point()[2]=25;
obst[4].dimensions()[0]=10;
obst[4].dimensions()[1]=10;
obst[4].dimensions()[2]=25;

double Angle_degrees=0;
/*
for (int i=0; i<3; ++i)
{
drones[i].body().set_Cub(drones[i].middle_point(), drones[i].dimensions());
for (int j=0; j<4; ++j)
{
Angle_degrees=0;
JumpAngle_degrees*=-1;

drones[i].rotor(j).set_Prism(drones[i].body()[j+4], R, Thickness, Angle_degrees, JumpAngle_degrees);
}
}
*/
for (int i=0; i<5; ++i)
obst[i].obst().set_Cub(obst[i].middle_point(), obst[i].dimensions());

for (int i=0; i<3; ++i)
drones[i].set_Drone(R, Thickness, JumpAngle_degrees);

cout<<Vector3D::created_amount<<endl;
//cout<<Vector3D::exist_amount<<endl;


/*
if (!ObstacleWriteToFile("Drone1.dat",  scene.Drones.back().get())) return 1;
//if (!DroneWriteToFile("Drone2.dat", drones[1])) return 1;
//if (!DroneWriteToFile("Drone3.dat", drones[2])) return 1;
if (!ObstacleWriteToFile("Obstacle1.dat", obst[0].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle2.dat", obst[1].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle3.dat", obst[2].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle4.dat", obst[3].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle5.dat", obst[4].obst())) return 1;*/

if (!WriteToFile("Scena.dat", scene.objects())) return 1;
Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');
cout<<Vector3D::created_amount<<endl;
//cout<<Vector3D::exist_amount<<endl;

/*


  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');
cout<<Vector3D::created_amount<<endl;
//cout<<Vector3D::exist_amount<<endl;
*/
/*
cout<<"o - obrot drona o zadany kat"<<endl;
cout<<"m - wyswietl menu"<<endl;
cout<<"j - lot na wprost"<<endl;
cout<<"k - koniec dzialania programu"<<endl;

while (end)
{   cout<<endl<<"Twoj wybor? (m - menu) >";
    cin>>op;
    cout<<endl<<endl;

switch(op){
    case 'm':
    {cout<<"o - obrot drona o zadany kat"<<endl;
    cout<<"m - wyswietl menu"<<endl;
    cout<<"j - lot na wprost"<<endl;
    cout<<"k - koniec dzialania programu"<<endl;}
    break;
   case 'o': {
    cout<<"Prosze podac numer dronu";
    cin>>drone_int;
    cout<<endl;
    cout<<"Prosze podac kat obrotu: ";
    cin>>angle;
    cout<<endl;

    cout<<"Podaj szybkosc obrotu drona: ";
    cin>>rotation_speed;
    cout<<endl;

    cout<<"Podaj szybkosc obrotu wirnikow: ";
    cin>>rotor_speed;
    cout<<endl;

    cout<<"Podaj ile razy szybciej/wolniej ma obracac sie jedna para wirnikow: ";
    cin>>scale;
    cout<<endl;

    amount=abs(angle/rotation_speed);
    if (angle<0) rotation_speed*=-1;
    front_angle+=angle;

    for ( int i=0; i<amount; ++i)
        {

        drones[drone_int].body().OwnRotate(rotation_speed);
        middle[0]=(drones[drone_int].body()[0][0]+drones[drone_int].body()[2][0])/2;
        middle[1]=(drones[drone_int].body()[0][1]+drones[drone_int].body()[2][1])/2;
        middle[2]=drones[drone_int].body()[0][0];



        for (int j=0; j<4; ++j)
            {
            drones[drone_int].rotor(j).Point_Rotate(rotation_speed, middle);
            if (j%2) drones[drone_int].rotor(j).Point_Rotate(rotor_speed*scale, drones[drone_int].body()[j]);
                else drones[drone_int].rotor(j).Point_Rotate(-rotor_speed/scale, drones[drone_int].body()[j]);
            }


if (!DroneWriteToFile("Drone1.dat", drones[0])) return 1;
//if (!DroneWriteToFile("Drone2.dat", drones[1])) return 1;
//if (!DroneWriteToFile("Drone3.dat", drones[2])) return 1;
if (!ObstacleWriteToFile("Obstacle1.dat", obst[0].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle2.dat", obst[1].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle3.dat", obst[2].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle4.dat", obst[3].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle5.dat", obst[4].obst())) return 1;


        Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        usleep(200000);

        }

        cout<<Vector3D::created_amount<<endl;
        //cout<<Vector3D::exist_amount<<endl;
}
break;
    case 'j':
    {
    cout<<"Prosze podac numer dronu";
    cin>>drone_int;
    cout<<endl;
        cout<<"Podaj dlugosc drogi przelotu i kat wznoszenia (+)/ opadania (-)."<<endl;
        cout<<"Dlugosc drogi: ";
        cin>>distance;
        cout<<endl;
        cout<<"Kat wznoszenia (stopnie): ";
        cin>>angle;
        cout<<endl;
        cout<<"Podaj szybkosc lotu: ";
        cin>>fly_speed;
        cout<<endl;
        cout<<"Podaj szybkosc obrotu wirnikow: ";
        cin>>rotor_speed;
        cout<<endl;
        cout<<"Podaj ile razy szybciej/wolniej ma obracac sie jedna para wirnikow: ";
        cin>>scale;
        cout<<endl;
        amount=abs(distance/fly_speed);
        if (distance<0) fly_speed*=-1;
        for ( int i=0; i<amount; ++i)
            {
            drones[drone_int].body().fly(fly_speed, angle, front_angle);

            for (int j=0; j<4; ++j)
            {
            drones[drone_int].rotor(j).fly(fly_speed, angle, front_angle);
            if (j%2) drones[drone_int].rotor(j).Point_Rotate(rotor_speed*scale, drones[drone_int].body()[j]);
                else drones[drone_int].rotor(j).Point_Rotate(-rotor_speed/scale, drones[drone_int].body()[j]);
            }

if (!DroneWriteToFile("Drone1.dat", drones[0])) return 1;
if (!DroneWriteToFile("Drone2.dat", drones[1])) return 1;
if (!DroneWriteToFile("Drone3.dat", drones[2])) return 1;
if (!ObstacleWriteToFile("Obstacle1.dat", obst[0].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle2.dat", obst[1].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle3.dat", obst[2].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle4.dat", obst[3].obst())) return 1;
if (!ObstacleWriteToFile("Obstacle5.dat", obst[4].obst())) return 1;


            Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
            usleep(200000);
            }
            cout<<Vector3D::created_amount<<endl;
            //cout<<Vector3D::exist_amount<<endl;
    }
    break;
    case 'k': end=false;
    break;

    default: cout<<"Bledna opcja, wprowadz ponowanie swoja opcje"<<endl;
    break;
}
}
*/
cout<<Vector3D::created_amount<<endl;
//cout<<Vector3D::exist_amount<<endl;

cout<<"Koniec dzialania program"<<endl;
}

