#ifndef GLOBAL_H
#define GLOBAL_H

class Global
{
public:
        static void GenerateLife() { life = rand() % (10 - 4 + 1) + 4; }
        static void ModifyLife(int injury) { life += injury; }
        static int CheckLife() { return life; }

        static void InitCiri() { ciri = 0; }
        static void ModifyCiri(int pwet) { ciri += pwet; }
        static int CheckCiri() { return ciri; }

        static void ModifyMoney(int pwet) { money += pwet; }
        static int CheckMoney() { return money; }

protected:
    static int life;

    static int ciri;

    static int money;
};

#endif // GLOBAL_H
