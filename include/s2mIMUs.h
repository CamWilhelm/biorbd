#ifndef S2MIMUS_H
#define S2MIMUS_H
    #include "biorbdConfig.h"
    #include "s2mIMU.h"
    #include "s2mGenCoord.h"
    #include "s2mMatrix.h"

class s2mJoints;
class BIORBD_API s2mIMUs
{
    public:
        s2mIMUs();
        ~s2mIMUs();

        // Set and get
        void addIMU(const s2mAttitude &pos = s2mAttitude(),
                       const s2mString &name = "",
                       const s2mString &parentName = "",
                       const bool &technical = true,
                       const bool &anatomical = false,
                       const int &id = -1); // Ajouter un nouveau marker
        unsigned int nIMUs() const; // Retourne le nombre de marqueurs

        std::vector<s2mString> IMUsNames();
        std::vector<s2mString> technicalIMUsNames();
        std::vector<s2mString> anatomicalIMUsNames();

        std::vector<s2mIMU> IMU(); // Retour d'un STL vector de tous les IMU
        std::vector<s2mIMU> IMU(s2mJoints& m, unsigned int idx); // Retour d'un STL vector de tous les IMU d'un segment idx
        s2mIMU IMU(const unsigned int&); // Retour d'un IMU ind idx

        std::vector<s2mIMU> IMU(s2mJoints& model, const s2mGenCoord &Q, const bool &updateKin = true); // Retour d'un STL vector de tous les IMUs
        s2mIMU IMU(s2mJoints& model, const s2mGenCoord&, const unsigned int&, const bool &updateKin = true); // Retour d'un IMU ind idx
        std::vector<s2mIMU> segmentIMU(s2mJoints& model, const s2mGenCoord&, const unsigned int&, const bool &updateKin = true); // Retour d'un STL vector de tous les IMUs d'un segment


        unsigned int nTechIMUs(); // Retourne le nombre de marqueurs techniques
        unsigned int nAnatIMUs(); // Retourne le nombre de marqueurs anatomiques
        std::vector<s2mIMU> technicalIMU(s2mJoints& model, const s2mGenCoord &Q, bool updateKin = true); // Retour d'un STL vector de tous les IMUs
        std::vector<s2mIMU> technicalIMU(); // Retour d'un STL vector de tous les IMUs
        std::vector<s2mIMU> anatomicalIMU(s2mJoints& model, const s2mGenCoord &Q, bool updateKin = true); // Retour d'un STL vector de tous les IMUs
        std::vector<s2mIMU> anatomicalIMU(); // Retour d'un STL vector de tous les IMUs




        std::vector<s2mMatrix> IMUJacobian(s2mJoints& model, const s2mGenCoord &Q, const bool &updateKin = true); // Retourne la jacobienne des Tags
        std::vector<s2mMatrix> TechnicalIMUJacobian(s2mJoints& model, const s2mGenCoord &Q, const bool &updateKin = true); // Retourne la jacobienne des Tags pour les marqueurs techniques

    protected:
        std::vector<s2mMatrix> IMUJacobian(s2mJoints& model, const s2mGenCoord &Q, const bool &updateKin, bool lookForTechnical); // Retourne la jacobienne des Tags

        std::vector <s2mIMU> m_IMUs;
    private:
};

#endif // S2MIMU_H
