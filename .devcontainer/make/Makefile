define error_exit
	echo "  ${1}" && exit 1
endef

utils_PATH := $(HOME)/.config/latex-utils
hsnips_PATH := $(HOME)/.config/HyperSnips

COMMON_FILES := $(wildcard ./common/*.tex)
LOGOS_FILES := $(wildcard ./logos/*.*)
common_dest_files := $(patsubst ./common/%.tex, ${utils_PATH}/common/%.tex, $(COMMON_FILES))
logos_dest_files := $(patsubst ./logos/%, ${utils_PATH}/logos/%, $(LOGOS_FILES))

git_user := FluffLescure
git_mail := lucas.lescure1@gmail.com


all : intro directories common logos snippets git
	@echo "Setup completed successfully"
	@sed -i "s|/home/archlinux/.config/HyperSnips|${hsnips_PATH}|g" ../../.vscode/settings.json; 
	@if [ ! -f ../../Makefile ]; then \
		cp .Makefile ../../Makefile;\
		echo "Makefile link created";\
    fi
	@if test -e ~/.vscode; then \
		cp ../everforest-dark.json ~/.vscode/extensions/sainnhe.everforest-0.3.0/themes/everforest-dark.json; \
		echo "everforest-dark.json copied to vscode"; \
	fi
	@if test -e ~/.vscode-server; then \
		cp ../everforest-dark.json ~/.vscode-server/extensions/sainnhe.everforest-0.3.0/themes/everforest-dark.json; \
		echo "everforest-dark.json copied to vscode-server"; \
	fi
	@if test -e ~/.vscode-remote; then \
		cp ../everforest-dark.json ~/.vscode-remote/extensions/sainnhe.everforest-0.3.0/themes/everforest-dark.json; \
		echo "everforest-dark.json copied to vscode-remote"; \
	fi






intro :
	@echo "The latex-utils directory path will be: ${utils_PATH}"; \
	echo "The HyperSnips directory path will be: ${hsnips_PATH}"; \
		

directories :
	@if test -e ${utils_PATH} && test -e ${hsnips_PATH} && test -e ${utils_PATH}/common && test -e ${utils_PATH}/logos; then \
		echo "Directories already exist"; \
	else \
		mkdir -p ${utils_PATH} ${hsnips_PATH} ${utils_PATH}/common ${utils_PATH}/logos; \
		if [ $$? -ne 0 ]; then \
			$(call error_exit, "Error creating directories"); \
		else \
			echo "Directories successfully created"; \
		fi; \
	fi


${utils_PATH}/common/%.tex: ./common/%.tex
	@echo "Unpacking $< to $@"
	@rsync $< $@

common: $(common_dest_files) 
	@echo "Files in ./common successfully unpacked"

${utils_PATH}/logos/%: ./logos/%
	@echo "Unpacking $< to $@"
	@rsync $< $@

logos :$(logos_dest_files) 
	@echo "Files in ./logos successfully unpacked"

snippets : 
	@echo "Unpacking latex.hsnips to ${hsnips_PATH}/latex.hsnips"; \
	cp  latex.hsnips ${hsnips_PATH}/latex.hsnips; \
	if [ $$? -ne 0 ]; then \
		$(call error_exit, "Error unpacking latex.hsnips"); \
	else \
		echo "File latex.hsnips successfully unpacked"; \
	fi

git : 
	@echo "Setting up git config"; \
	echo "Username : ${git_user}"; \
	echo "Email : ${git_mail}"; 	
	@git config --global user.name ${git_user}; \
	git config --global user.email ${git_mail}; \
	if [ $$? -ne 0 ]; then \
		$(call error_exit, "Error setting up git config"); \
	else \
		echo "git config successfully set"; \
	fi

${Makefile} : 
	@if [ ! -e ${Makefile} ]; then \
		ln -s Makefile $(HOME)/Makefile; \
		echo "Created Makefile link to $(HOME)"; \
	fi


clean :
	rm -r ${utils_PATH}
	rm -r ${hsnips_PATH}
