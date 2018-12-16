/*
@author:CodingMengmeng
@theme:��ȡָ���ļ����µ������ļ���
@time:2017-1-13 11:46:22
@blog:http://www.cnblogs.com/codingmengmeng/
*/
#include <io.h>  
#include <iostream>  
#include <vector>  
using namespace std;

void getFiles(string path, vector<string>& files)
{
    //�ļ����  
    long   hFile = 0;
    //�ļ���Ϣ������һ���洢�ļ���Ϣ�Ľṹ��  
    struct _finddata_t fileinfo;
    string p;//�ַ��������·��
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)//�����ҳɹ��������
    {
        do
        {
            //�����Ŀ¼,����֮�����ļ����ڻ����ļ��У�  
            if ((fileinfo.attrib &  _A_SUBDIR))
            {
                //�ļ���������"."&&�ļ���������".."
                //.��ʾ��ǰĿ¼
                //..��ʾ��ǰĿ¼�ĸ�Ŀ¼
                //�ж�ʱ�����߶�Ҫ���ԣ���Ȼ�����޵ݹ�������ȥ�ˣ�
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            //�������,�����б�  
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        //_findclose������������
        _findclose(hFile);
    }
}


int main(){
    char * filePath;//�Լ�����Ŀ¼  
    cin >> filePath;
    vector<string> files;

    ////��ȡ��·���µ������ļ�  
    getFiles(filePath, files);

    char str[30];
    int size = files.size();
    for (int i = 0; i < size; i++)
    {
        cout << files[i].c_str() << endl;
    }
}
