class Calculator{
    private :
        int a;
        int b;
        int add_cnt;
        int div_cnt;
        int mul_cnt;
        int min_cnt;

    public :
        void Init();
        double Add(double a, double b);
        double Div(double a, double b);
        double Mul(double a, double b);
        double Min(double a, double b);
        void showOpCount();
};