#include <iostream>
#include <memory>

class K{
  public:

    int* a;
    void * ptr;
    std::shared_ptr<void> m_sptr; 

    K(){
      a = new int(5);
      ptr=a;
      m_sptr = std::shared_ptr<void>(ptr, [](void* d){std::cout<<"deleter\n";});
    }

/*
    std::shared_ptr<void> Ptr(){
      std::shared_ptr<void> sptr(ptr, [](void* d){std::cout<<"deleter\n";});
      return sptr;
    }
*/
  std::shared_ptr<void> Ptr(){return m_sptr;};
};

int main(){

  K k;
  std::cout<<*(static_cast<int*>(k.Ptr().get()))<<std::endl;

  std::cout<<*k.a<<std::endl;
  std::cout<<*(static_cast<int*>(k.ptr))<<std::endl;
 
  std::cout<<*(static_cast<int*>(k.Ptr().get()))<<std::endl;

  /*
  int *b = new int(6);
  void * bptr = new int(55);
  std::cout<<*(static_cast<int*>(bptr));
  */

  return 0;
}
