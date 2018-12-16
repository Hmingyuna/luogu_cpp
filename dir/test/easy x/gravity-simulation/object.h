
#ifndef OBJECT_H
#define OBJECT_H

#include"vector.h"
#include<list>

namespace gravitation
{
	class object
	{
		friend void stepforward();							//����
		friend void zoarium(object&,object&);				//��ײ����
	public:
		object(data_type mass=0,							//����
			data_type radius=0,								//�뾶
			const vector position=vector(),				//λ��
			const vector velocity=vector());				//�ٶ�
		~object();

		data_type mass()const					{return _mass;}
		data_type radius()const					{return _radius;}
		vector position()const					{return _position;}
		vector velocity()const					{return _velocity;}
		vector acceleration()const				{return _acceleration;}

		void mass(const data_type& value)		{_mass=value;}
		void radius(const data_type& value)		{_radius=value;}
		void position(const vector& vec)		{_position=vec;}
		void velocity(const vector& vec)		{_velocity=vec;}

		data_type distance(const object&)const;				//����


		static void setdt(const data_type&);				//������

	private:
		data_type _mass;						//����
		data_type _radius;						//�뾶

		vector _position;						//Բ��
		vector _velocity;						//�ٶ�
		vector _acceleration;					//���ٶ�

		static std::list<object*> allobj;		//��������object�ĵ�ַ

		static data_type dt;					//������

		static const data_type G;				//������������

		std::list<object*>::iterator it;
		
		object(const object&);					//��ֹ����
		object &operator=(const object&);

		//������ٶ�
		int calcacce();
		int step();
	};
	

	vector operator-(const object&,const object&);//ָ������

}

#endif