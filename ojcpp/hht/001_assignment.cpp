//
// Created by rui zhou on 30/01/19.
//

#include <codech/codech_def.h>

//mystring impl
//添加赋值运算符
//当一个异常被抛出，异常安全的函数应该：
//没有资源泄露。上面的代码没有通过这个测试，因为如果 "new Image(imgSrc)" 表达式产生一个异常，
// 对 unlock 的调用就永远不会执行，而那个互斥体也将被永远挂起。
//不允许数据结构恶化。如果 "new Image(imgSrc)" 抛出异常，bgImage 被遗留下来指向一个被删除对象。
// 另外，尽管并没有将一张新的图像设置到位，imageChanges 也已经被增加。（在另一方面，旧的图像被明确地删除，所以我料想你会争辩说图像已经被“改变”了。）

namespace HHT
{
    class CMyString
    {
    public:
        CMyString(char*pData=NULL){
            m_pData = new char[strlen(pData)+1];
            strcpy(m_pData, pData);
        }

        // TODO
        CMyString(const CMyString &str) {

        }

        ~CMyString(){
            if (m_pData)
                delete m_pData;
        }
    private:
        char *m_pData;

    public:
        // not good impl /////////////////////////
//        CMyString& operator=(const CMyString&rhs)
//        {
//            if (this==&rhs)
//                return *this;
//            delete []m_pData;
//            m_pData = nullptr;
//            // if we get exception at the below line, the this status will be abnormal.
//            m_pData = new char[strlen(rhs.m_pData)+1];
//            strcpy(m_pData, rhs.m_pData);
//        }
        // better solution
        CMyString&operator=(const CMyString&rhs) {
            if (this!=&rhs) {
                CMyString tmp(rhs);
                swap(*this, tmp);
            }

            return *this;
        }
    };
}

DEFINE_CODE_TEST(hht_string_impl)
{
    HHT::CMyString str1,str2;
    str2=str1;

}