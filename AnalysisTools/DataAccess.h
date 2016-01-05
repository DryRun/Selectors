#ifndef DataAccess_h
#define DataAccess_h

#include <iostream>

#include <TString.h>

#include "xAODRootAccess/TEvent.h"

class DataAccess {
public:
	enum DataSource {
		kCollisionData,
		kSimulation
	};

/*** Methods ***/

public:
	DataAccess();

	virtual ~DataAccess();

	inline void SetDataSource(DataSource p_source) {
		if (p_source == kCollisionData) {
			Info("SetDataSource()", "Setting data source to kCollisionData.");
		} else if (p_source == kSimulation) {
			Info("SetDataSource()", "Setting data source to kSimulation.");
		} else {
			Error("SetDataSource()", "Unknown data source.");
			exit(1);
		}
		data_source_ = p_source;
	}

	inline DataSource GetDataSource() {
		return data_source_;
	}

	inline void SetEvent(xAOD::TEvent* p_event) {
		event_ = p_event;
	}

	inline const xAOD::TEvent* GetEvent() {
		return event_;
	}

	inline void IgnoreBranch(TString p_branch) {
		ignore_branch_[p_branch] = true;
	}

protected:

/*** Members ***/
protected:
	DataSource data_source_; //!
	xAOD::TEvent* event_; //!
	std::map<TString, bool> ignore_branch_; //!


private:

	ClassDef(DataAccess, 1);
};


#endif