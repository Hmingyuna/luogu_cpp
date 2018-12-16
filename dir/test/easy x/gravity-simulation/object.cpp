
#include"object.h"
#include<algorithm>
#include<functional>
namespace gravitation
{
	std::list<object*> object::allobj;
	data_type object::dt(0.00002);					//��������ԽСԽ��ȷ���ٶ�Խ��
	const data_type object::G(1);					//��Ϊ1���׼���

	object::object(data_type mass,					//����
					data_type radius,				//�뾶
					const vector position,			//λ��
					const vector velocity)			//�ٶ�
					:_mass(mass),_radius(radius),_position(vector(position)),_velocity(vector(velocity)),_acceleration(vector())
	{
		it=allobj.insert(allobj.end(),this);		//��¼
	}

	object::~object()
	{
		allobj.erase(it);
	}

	//ָ������
	vector operator-(const object& lhs,const object& rhs)
	{
		return lhs.position()-rhs.position();
	}

	//����
	data_type object::distance(const object& obj)const
	{
		return (obj.position()-this->position()).magnitude();
	}

	//������ٶ�
	int object::calcacce()
	{
		_acceleration=vector();														//����
		for(std::list<object*>::iterator i=allobj.begin();i!=allobj.end();++i)								//�ϼ��ٶ�
		{
			if(*i!=this)
			{
				if(this->distance(**i)>(this->radius()+(*i)->radius()))				//δ������ײ
				_acceleration+=														//a=sqrt(GM/(r*r))
					vector((**i)-(*this),(*i)->mass()*G
						/(((this->position()-(*i)->position()).magnitude())
						 *((this->position()-(*i)->position()).magnitude())));
				else if(this->position()!=(*i)->position())
					zoarium(*this,**i);												//��ײ����
			}
		}
		return 0;
	}

	//���ü�����
	void object::setdt(const data_type& val)
	{
		dt=val;
	}

	int object::step()
	{
		_position+=_velocity*dt;
		_velocity+=_acceleration*dt;
		return 0;
	}

	//����
	void stepforward()
	{
		std::for_each(object::allobj.begin(),object::allobj.end(),std::mem_fun(&object::calcacce));		//������ٶ�
		std::for_each(object::allobj.begin(),object::allobj.end(),std::mem_fun(&object::step));
	}


	//����
	void zoarium(object& ob1,object& ob2)
	{
		ob1.position(ob1.position()+((ob2.position()-ob1.position())*(ob2.mass()/(ob1.mass()+ob2.mass()))));		//������ȷ��λ��
		ob2.position(ob1.position());
		ob1.velocity((ob1.velocity()*ob1.mass()+ob2.velocity()*ob2.mass())*(1/(ob1.mass()+ob2.mass())));			//�����غ�
		ob2.velocity(ob1.velocity());
	}
}

