#pragma once
#include "Application.h"


class QBert : public Hidden::Application
{
public:
	QBert() = default;
	~QBert() = default;

	// Overrides default demo load game defined in Application class
	virtual void LoadGame() const override;

	virtual void Initialize() override;

	// Called after the game loop is over, used to delete anything created in the load game function 
	void Cleanup();

private:

};