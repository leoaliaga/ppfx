#ifndef MIPPNUMIMC_H
#define MIPPNUMIMC_H

#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <iostream>
#include <sstream>

namespace NeutrinoFluxReweight{
  
  /*! \class MIPPNumiMC
   *  \brief A class to manage the MC value for MIPP NuMI. 
   */
  class MIPPNumiMC{

  private:
    MIPPNumiMC();

  public:
    static MIPPNumiMC* getInstance();
    
    //! Read a xml file name to get the mc value for pip
    void pip_mc_from_xml(const char* filename);

    //! Read a xml file name to get the mc value for pim
    void pim_mc_from_xml(const char* filename);

   //! Read a xml file name to get the mc value for kap
    void kap_mc_from_xml(const char* filename);

    //! Read a xml file name to get the mc value for kam
    void kam_mc_from_xml(const char* filename);
    
    //! Read a xml file name to get the mc value for k0l
    void k0l_mc_from_xml(const char* filename);

    //! Read a xml file name to get the mc value for k0s
    void k0s_mc_from_xml(const char* filename);

    //! MC value for this HP production
    double getMCval(double pz,double pt, int pdgcode);

  private:    
    std::vector<double> pip_cv,pim_cv,kap_cv,kam_cv,k0l_cv,k0s_cv;
    std::vector<double> v_pzmin,v_pzmax,v_ptmin,v_ptmax;
    bool ranges_already_filled;
    double proton_no_interacting;
    static MIPPNumiMC* instance;
    
  };

  
  
}
#endif
