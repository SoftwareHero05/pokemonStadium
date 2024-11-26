#include <MOVES/Move.h>



int MovExecuter(int idMov, Pokemon *User, Pokemon *Enemy) {
    int DamageDone = 0;
    cout<<User->getNombre()<<" utilizo ";
    // Inicializamos para garantizar que siempre tenga un valor.
    switch (idMov) {
        case 1: {
            Move
            AuraSphere *MovAura = new AuraSphere();
            DamageDone = ceil(MovAura->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovAura;
            break;
        }
        case 2: {
            /*IronHead *MovIron= new IronHead();
            DamageDone = ceil(MovIron->ExecuteMove(Enemy->Def, User->Atk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovIron;*/
            break;
        }
        case 3: {
            cout<<"DragonPulse"<<endl;
            DragonPulse *MovPulse = new DragonPulse();
            DamageDone = ceil(MovPulse->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovPulse;
            break;
        }
        case 4: {
            cout<<"Flamethrower"<<endl;
            Flamethrower *MovFlame = new Flamethrower();
            DamageDone = ceil(MovFlame->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovFlame;
            break;
        }
        case 5: {
            cout<<"AirSlash"<<endl;
            AirSlash *MovAir = new AirSlash();
            DamageDone = ceil(MovAir->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovAir;
            break;
        }
        case 6: {
            cout<<"DragonClaw"<<endl;
            DragonClaw *MovClaw = new DragonClaw();
            DamageDone = ceil(MovClaw->ExecuteMove(Enemy->Def, User->Atk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovClaw;
            break;
        }
        case 7: {
            cout<<"EarthQuake"<<endl;
           Earthquake *MovQuake = new Earthquake();
            DamageDone = ceil(MovQuake->ExecuteMove(Enemy->Def, User->Atk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovQuake;
            break;
        }
        case 8: {
            cout<<"Crunch"<<endl;
            Crunch *MovCrunch = new Crunch();
            DamageDone = ceil(MovCrunch->ExecuteMove(Enemy->Def, User->Atk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovCrunch;
            break;
        }
        case 9:{
            cout<<"Calm Mind"<<endl;
            CalmMind(User);
            cout<<"Ataque Especial y Defensa Especial Aumentados!"<<endl;
            system("pause");
            system("cls");
            break;
        }
        case 10:{
            cout<<"Dragon Dance"<<endl;
            DragonDance(User);
            cout<<"Ataque y Velocidad Aumentados!"<<endl;
            system("pause");
            system("cls");
            break;
        }
        case 11:{
            cout<<"MoonBlast"<<endl;
            MoonBlast *MovMoon = new MoonBlast();
            DamageDone = ceil(MovMoon->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovMoon;
            break;
        }
        case 12:{
            cout<<"Psychic"<<endl;
            Psychic *MovPsychic = new Psychic();
            DamageDone = ceil(MovPsychic->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovPsychic;
            break;
        }
        case 13:{
            cout<<"ShadowBall"<<endl;
            ShadowBall *MovShadow = new ShadowBall();
            DamageDone = ceil(MovShadow->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovShadow;
            break;
        }
        case 14:{
            cout<<"FlashCannon"<<endl;
            FlashCannon *MovFlash = new FlashCannon();
            DamageDone = ceil(MovFlash->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovFlash;
            break;
        }
         case 15:{
            cout<<"IceBeam"<<endl;
            IceBeam *MovIce = new IceBeam();
            DamageDone = ceil(MovIce->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovIce;
            break;
        }
        case 16:{
            cout<<"Surf"<<endl;
            Surf *MovSurf = new Surf();
            DamageDone = ceil(MovSurf->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovSurf;
            break;
        }
         case 17:{
            cout<<"EnergyBall"<<endl;
            EnergyBall *MovEnergy = new EnergyBall();
            DamageDone = ceil(MovEnergy->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovEnergy;
            break;
        }
         case 18:{
            cout<<"SludgeBomb"<<endl;
            SludgeBomb *MovSludge = new SludgeBomb();
            DamageDone = ceil(MovSludge->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovSludge;
            break;
        }
        case 19:{
            cout<<"Synthesis"<<endl;
            Synthesis(User);
            cout<<"Recupera algo de Hp!"<<endl;
            system("pause");
            system("cls");
            break;
        }
        case 20:{
            cout<<"EarthPower"<<endl;
            EarthPower *MovEarth = new EarthPower();
            DamageDone = ceil(MovEarth->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovEarth;
            break;
        }
        case 21:{
            cout<<"StoneEdge"<<endl;
            StoneEdge *MovStone = new StoneEdge();
            DamageDone = ceil(MovStone->ExecuteMove(Enemy->Def, User->Atk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovStone;
            break;
        }
        case 22:{
            cout<<"ThunderBolt"<<endl;
            ThunderBolt *MovThunder = new ThunderBolt();
            DamageDone = ceil(MovThunder->ExecuteMove(Enemy->SDef, User->SAtk, Enemy->Type1, Enemy->Type2, User->Type1, User->Type2));
            delete MovThunder;
            break;
        }
        case 23:{
            cout<<"Nasty Plot"<<endl;
            NastyPlot(User);
            cout<<"Ataque especial aumenta mucho!"<<endl;
            system("pause");
            system("cls");
            break;
        }
        default:
            DamageDone = 0;
            break;
    }
    return DamageDone;
}