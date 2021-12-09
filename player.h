class Player{
    public:
        void strike(Enemy);
        void hitBy(Enemy) = 0;
        void consume(RH);
        void consume(BA);
        void consume(BD);
        void consume(PH);
        void consume(WA);
        void consume(SmallPile);
        void consume(NormalPile);
        void consume(MerchantHoard);
        void consume(DragonHoard);
};