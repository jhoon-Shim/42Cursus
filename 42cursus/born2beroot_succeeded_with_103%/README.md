*This project has been created as part of the 42 curriculum by jshim.*

# Born2Beroot: My first virtual machine

## 1. Description
This project is an introduction to the world of virtualization. The goal is to set up a strictly configured server using VirtualBox, implementing specific security rules and service management. As a server environment, this system operates without any graphical interface (GUI), installing only a minimal set of services to ensure efficiency and security.

## 2. Technical Choices and Comparisons

### 2.1. Operating System: Debian
For this project, **Debian** was chosen as the operating system.
*   **Pros**: High stability, extensive documentation, and a robust package management system (APT/Aptitude). It is highly recommended for those new to system administration.
*   **Cons**: Some packages might be older than those in "rolling release" distributions, and the minimal installation requires significant manual configuration.

### 2.2. Comparisons
| Category | Choice A (Debian Based) | Choice B (Rocky Based) | Key Differences |
| :--- | :--- | :--- | :--- |
| **OS** | **Debian** | Rocky Linux | Debian is community-led and stable; Rocky is a RHEL downstream focusing on enterprise. |
| **Security** | **AppArmor** | SELinux | AppArmor uses path-based MAC; SELinux uses label-based MAC and is generally more complex. |
| **Firewall** | **UFW** | firewalld | UFW (Uncomplicated Firewall) is designed for simplicity; firewalld uses zones and is the default for RHEL-likes. |
| **Virtualizer** | **VirtualBox** | UTM | VirtualBox is a cross-platform type-2 hypervisor; UTM is specifically optimized for Apple Silicon (macOS). |

### 2.3. Design Choices
*   **Partitioning**: Encrypted LVM (Logical Volume Management) was implemented to ensure data security and flexibility in volume resizing.
*   **Security Policies**: Strict password complexity (PAM) and sudo logging policies were enforced to prevent unauthorized access and track administrative actions.
*   **User Management**: The primary user `jshim` is assigned to the `sudo` and `user42` groups, adhering to the principle of least privilege while maintaining administrative capability.
*   **Services**: Only SSH (Port 4242) and a monitoring script are active, minimizing the attack surface.

## 3. Useful commands

### 3.1. Basic Verification
*   **Check GUI (Must be text mode)**: `systemctl get-default` (Should be `multi-user.target`)
*   **Check OS Version**: `hostnamectl` or `cat /etc/os-release`
*   **Check AppArmor Status**: `sudo aa-status`

### 3.2. User & Group Management
*   **Check Groups**: `groups jshim`
*   **Add New User**: `sudo adduser <new_user>`
*   **Create Group**: `sudo addgroup <group>`
*   **See all Groups**: `cat /etc/group`
*   **Delete Group**: `sudo groupdel <group>` 
*   **Assign Group**: `sudo usermod -aG <group> <new_user>`
*   **delted user from group**: `sudo gpasswd -d <user> <group>`
*   **Delete user**: `deluser <username> <group>`

### 3.3. Hostname & Partitioning
*   **Check Hostname**: `hostname`
*   **Modify Hostname**: `sudo hostnamectl set-hostname <new_name>`
*   **Check LVM Partitions**: `lsblk`

### 3.4. Sudo Configuration
*   **Verify Sudo Rules**: `sudo cat /etc/sudoers.d/sudo_config`
*   **Check Sudo Logs**: `ls /var/log/sudo/`
*   **Replay Sudo Sessions**: `sudo sudoreplay -d /var/log/sudo -l`

### 3.5. Firewall (UFW) & SSH
*   **UFW Status**: `sudo ufw status`
*   **Add/Delete Rule**: `sudo ufw allow <port>` / `sudo ufw delete allow <port>`
*   **SSH Config**: `sudo nano /etc/ssh/sshd_config` (Verify Port 4242 & PermitRootLogin no)
*   **Check Active Ports**: `ss -tunlp`
*   **Check SSH status**: `systemctl status ssh`

### 3.6. Monitoring & Cron
*   **Check Cron Job**: `sudo crontab -l`
*   **Modify Cron Frequency**: `sudo crontab -e` (Change `*/10` to `*/1`)
*   **Manual Script Run**: `sudo /usr/local/bin/monitoring.sh`

### 3.7. PW and Log
*   **Check PW rule1**: `nano /etc/login.defs` or `sudo chage -l jshim`
*   **Check PW rule2**: `nano /etc/pam.d/common-password`
*   **Check it out**: `visudo /etc/sudoers.d/sudo_config`

## 4. Instructions
1.  **Installation**: Follow the Debian netinst process without selecting any Desktop Environment.
2.  **Signature**: After setup, power off the VM and run `sha1sum <vm_name>.vdi` on the host machine.
3.  **Execution**: Launch the VM and log in via SSH: `ssh jshim@localhost -p <host_port>`.

## 5. Resources and AI Usage
*   **Documentation**: Debian Administration Handbook, Sudoers Manual.
*   **AI Usage**: AI was used to debug the monitoring script logic, verify the correct syntax for PAM complexity rules, and summarize the differences between AppArmor and SELinux.
