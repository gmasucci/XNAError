#include <windows.h>
#include <xnamath.h>

class Camera
{
protected:
	XMFLOAT4 position_;
	XMFLOAT4 up_;
	XMFLOAT4 look_;

	XMMATRIX	view_;
public:
	Camera()
		: position_( 0.0f, 1.0f, -5.0f, 0.0f )
		, up_( 0.0f, 1.0f, 0.0f, 0.0f )
		, look_( 0.0f, 1.0f, 0.0f, 0.0f )
	{

	}
	XMMATRIX const& Update()
	{
		XMVECTOR Eye	= XMVectorSet( position_.x, position_.y, position_.z, position_.w);
		XMVECTOR At		= XMVectorSet( look_.x, look_.y, look_.z, look_.w);
		XMVECTOR Up		= XMVectorSet( up_.x, up_.y, up_.z, up_.w);

		this->view_ =  XMMatrixLookAtLH( Eye, At, Up );
		return this->view_;
	}
};

int main()
{
	Camera* cam = new Camera;
	cam->Update();
}