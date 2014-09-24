
class CGame
{
public:
	bool Start();
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINADO,
		ESTADO_FINALIZADO
	};
	static CGame instanceGame;

	CGame();
	void Finalize();


private:
	int estado;
};