class Cellule {
    protected:
        int x;
        int y;
        bool state; // true for alive, false for dead 

    public:
        Cellule() {}
        Cellule(int x, int y, bool state) {}
        virtual ~Cellule() {}
        virtual int getX() {}
        virtual int getY() {}
        virtual bool getState() {}
        virtual void setX(int x) {}
        virtual void setY(int y) {}
        virtual void setState(bool state) {}
};