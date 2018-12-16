
#ifndef VECTOR_H
#define VECTOR_H

#define for if(0);else for	//�޸�VC6 BUG

namespace gravitation
{
	
	typedef double data_type;									//��������

	//�������
	class vector
	{
		friend bool operator==(const vector&,const vector&);
		friend vector operator-(const vector&,const vector&);	//ָ������
	public:
		vector(data_type=0,data_type=0,data_type=0);
		vector(const vector&);
		vector(const vector&,data_type);						//���򣬴�С

		const data_type& x()const{return _x;}
		const data_type& y()const{return _y;}
		const data_type& z()const{return _z;}

		void set(data_type x=0,data_type y=0,data_type z=0){_x=x;_y=y;_z=z;}

		vector& operator=(const vector&);
		vector& operator+=(const vector&);
		vector& operator*=(const data_type&);			//����
		
		bool samedirection(const vector&)const;			//����һ��
		vector direction()const;						//��ȡ����
		data_type magnitude()const;						//��ȡ��С
		void setmagnitude(const data_type&);			//���ô�С
		data_type distance(const vector&)const;			//��ȡ����
	private:
		data_type _x,_y,_z;
	};

	vector operator+(const vector&,const vector&);
	vector operator*(const vector&,const data_type&);

	inline bool operator==(const vector& lhs,const vector& rhs)
	{
		return lhs._x==rhs._x&&lhs._y==rhs._y&&lhs._z==rhs._z;
	}

	inline bool operator!=(const vector& lhs,const vector& rhs)
	{
		return !(lhs==rhs);
	}
}
#endif