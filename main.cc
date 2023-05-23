#include"ThreadPool.h"
std::mutex mu;
void Print(int num)
{
    std::unique_lock<std::mutex> lock(mu);
    std::cout<<"Print"<<num <<" : "<<(long int)syscall(SYS_gettid)<<std::endl;
}

int Incre(int a){
    return a+1; 
}


int main()
{
    int sum=0;
    {
        ThreadPool pool;
        for (int i = 0; i < 1000; i++)
        {
            std::future<int> f1 = pool.exec(Incre, i);
            sum += f1.get();
        }
        //pool.Destroy();
    }
    std::cout<<sum<<std::endl;
    std::cout<<"finsh"<<std::endl;
    return 0;
}