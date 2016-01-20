(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(indent-tabs-mode nil))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

;; Set <Return> to auto-indent C/C++ code
(add-hook 'c-mode-common-hook '(lambda ()
		(local-set-key (kbd "RET") 'newline-and-indent)))

;; Set tab width to 4 characters
(setq tab-width 4)
