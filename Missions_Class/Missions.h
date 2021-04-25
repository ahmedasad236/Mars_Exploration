enum M_Type { MOUNTAINOUS, POLAR, EMERGENCY };
enum M_State {WAITING,IN_EXCUTION,COMPLETED};
class Missions
{
	M_Type Type;
	double TargetLocation;
	double MissionDuration;
	int Significance;
	bool Assigned;
	M_State State;
	int StartDay;
public:
	Missions(M_Type);
	void setTargetLocation(double& targetLocation);
	double getTargetLocation();
	void ToEmergency();
	void setMissionDuration(double& targetLocation);
	double getMissionDuration();
	void setSignificance(int s);
	double getFactorOfImportance();
	void Assign();
	void InExecution();
	void Completed();
	M_State getState();
	void setStartDay(int);
	int getStartDay();
	int getLastDay(double,double);
};