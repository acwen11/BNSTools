namespace RNSReader {

void make_grid(double s_gp[SDIV + 1], double mu[MDIV + 1]);

void load_eos(char eos_file[], double log_e_table[201], double log_p_table[201],
              double log_h_table[201], double log_n0_table[201], int *n_tab);

double e_of_rho0(double rho0, double Gamma_P, double eos_k);

double e_at_p(double pp, double log_e_tab[201], double log_p_tab[201],
              int n_tab, int *n_nearest_pt, char eos_type[], double eos_k,
              double Gamma_P);

double p_at_e(double ee, double log_p_tab[201], double log_e_tab[201],
              int n_tab, int *n_nearest_pt);

double p_at_h(double hh, double log_p_tab[201], double log_h_tab[201],
              int n_tab, int *n_nearest_pt);

double h_at_p(double pp, double log_h_tab[201], double log_p_tab[201],
              int n_tab, int *n_nearest_pt);

double n0_at_e(double ee, double log_n0_tab[201], double log_e_tab[201],
               int n_tab, int *n_nearest_pt);

void make_center(double e_center, double log_e_tab[201], double log_p_tab[201],
                 double log_h_tab[201], int n_tab, char eos_type[],
                 double eos_k, double Gamma_P, double *p_center,
                 double *h_center);

void comp_values(double s_gp[SDIV + 1], double mu[MDIV + 1], double r_ratio,
                 double e_surface, double r_e, char eos_type[],
                 double log_e_tab[201], double log_n0_tab[201], int n_tab,
                 double Omega, double **rho, double **gama, double **alpha,
                 double **omega, double **energy, double **pressure,
                 double **enthalpy, double **velocity_sq, double *Mass,
                 double *Mass_0, double *T, double *W, double *Omega_K,
                 double *R_e, char rotation_type[], double **Omega_diff,
                 double *J);

double dm_dr_is(double r_is, double r, double m, double p, double e_center,
                double p_surface, double log_e_tab[SDIV + 1],
                double log_p_tab[SDIV + 1], int n_tab, int *n_nearest_pt,
                char eos_type[], double eos_k, double Gamma_P);

double dp_dr_is(double r_is, double r, double m, double p, double e_center,
                double p_surface, double log_e_tab[SDIV + 1],
                double log_p_tab[SDIV + 1], int n_tab, int *n_nearest_pt,
                char eos_type[], double eos_k, double Gamma_P);

double dr_dr_is(double r_is, double r, double m);

void integrate(int i_check, char eos_type[], double eos_k, double e_center,
               double p_center, double p_surface, double e_surface,
               double Gamma_P, double log_e_tab[201], double log_p_tab[201],
               double log_h_tab[201], int n_tab, double r_is_gp[RDIV + 1],
               double lambda_gp[RDIV + 1], double nu_gp[RDIV + 1],
               double *r_is_final, double *r_final, double *m_final);

void guess(double s_gp[SDIV + 1], char eos_type[], double eos_k,
           double e_center, double p_center, double p_surface, double e_surface,
           double Gamma_P, double log_e_tab[201], double log_p_tab[201],
           double log_h_tab[201], int n_tab, double **rho, double **gama,
           double **alpha, double **omega, double *r_e);

void iterate(double s_gp[SDIV + 1], double mu[MDIV + 1], char eos_type[],
             double eos_k, double log_e_tab[201], double log_p_tab[201],
             double log_h_tab[201], int n_tab, double Gamma_P, double r_ratio,
             double h_center, double enthalpy_min, int a_check, double accuracy,
             int print_dif, double cf, double *r_e_new, double **rho,
             double **gama, double **alpha, double **omega, double **energy,
             double **pressure, double **enthalpy, double **velocity_sq,
             double *Omega, char rotation_type[], double A_diff,
             double *Omega_e, double **Omega_diff, int RNS_lmax);

} // namespace RNSReader
